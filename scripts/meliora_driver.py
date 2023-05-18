import argparse
import os, sys
from signal import alarm, signal, SIGALRM, SIGKILL
from subprocess import PIPE, Popen
import time


'''
Driver for automating the process of data generation

@Kewen Meng

Example command:
python preprocess.py -extra time_cpu.o --  __orio_perftest10.c -DORIO_REPS=5

Please note this script is integrated into Orio as postprecessing
'''

class Alarm(Exception):
	pass


class Command(object):
	def __init__(self, cmd):
		self.cmd = cmd
		self.process = None

	def run(self, inputs='', timeout=-1, cwd=None, shell=True, kill_tree=True, env=None):
		'''
		Run a command with a timeout after which it will be forcibly
		killed.
		'''
		def alarm_handler(signum, frame):
			raise Alarm

		stdout = ''
		stderr = ''
		#Shravan
		#Modified universal_newlines = False
		p = Popen(self.cmd, shell = shell, cwd = cwd, stdin=PIPE, stdout = PIPE, stderr = PIPE, env = env, universal_newlines=False)
		
		if inputs: 
			p.stdin.write(inputs)
		
		if timeout != -1:
			signal(SIGALRM, alarm_handler)
			alarm(timeout)

		try:
			stdout, stderr = p.communicate()
			if timeout != -1:
				alarm(0)
		except Alarm:
			pids = [p.pid]
			#stdout, stderr = p.communicate()
			if kill_tree:
				pids.extend(self.get_process_children(p.pid))
			for pid in pids:
				# process might have died before getting to this line
				# so wrap to avoid OSError: no such process
				try: 
					os.kill(pid, SIGKILL)
				except OSError:
					pass
			return -9, stdout, stderr + "Killed!"
		return p.returncode, stdout, stderr
	
	def get_process_children(self, pid):
		p = Popen('ps --no-headers -o pid --ppid %d' % pid, shell=True,
			stdout=PIPE, stderr=PIPE)
		stdout, stderr = p.communicate()
		
		return [int(p) for p in stdout.split()]

if __name__ == '__main__':

	# parse command line
	parser = argparse.ArgumentParser(description='Driver for generating cfg data during Orio\'s processing')
	
	parser.add_argument('target', help='target program')
	parser.add_argument('flags', nargs='*', type=str,
						help='compiler flags parsed from Orio')
	parser.add_argument('-lp', '--lpath', help='absolute path of the custom cfg library',
						dest='lib_path', metavar='',
						default='/home/users/shravank/projects/meliora/datagen/build/cfgpass/libCfgPass.so')
	parser.add_argument('-o', '--output', dest='out_path', help='output path, not include file name', metavar='')
	parser.add_argument('-extra', '--params', dest='extra_params', nargs='+', help='extra compiler parameters', metavar='')
	#parser.add_argument('-opt', default='1', choices=['0', '1', '2', '3'],
	#					dest='opt_level', 
	#					help='optimization level, default is -O1')
	parser.add_argument('-input', dest='data', help='use if target depends on input data to run')
	args,unknown = parser.parse_known_args()
	#args = parser.parse_args()
	file_dir, file_name = os.path.split(args.target)

	print("Args.target: ",args.target)
	print("Args.flags: ",args.flags)

	out = args.out_path
	opt = ''
	if len(args.flags) > 0:
		#opt = ' '.join(args.flags)
		opt = args.flags
	elif len(args.flag) > 1:
		sys.stderr.write('Preprocessor not enabled for more than 1 clang flag: %s' % args.flags)
		sys.exit(1)
	lib_path = args.lib_path
	params =''
	if args.extra_params:
		params = ' '.join(args.extra_params)
	
	# current directory
	if not file_dir:
		file_dir = '.'

	# if user didn't specify output path
	# the intrumented binary will be output
	# to a directory in the same place as input
	if out is None:
		out = file_dir

	instru_dir = out + '/' + file_name + '.temp/'
	out_bin_name = file_name + '.instru'
	# choose C/C++
	compiler = ''
	if file_name.endswith('.C' or '.cpp'):
		compiler = 'clang++-9'
	else:
		compiler = '~/libs/llvm-14-meliora/bin/clang-14'
		###compiler = 'clang-9'
		
	# obtain branch possibility dynamically
	dyna_flag = False

	# some applications may need input data to run
	input_data = ''
	if args.data is not None:
		input_data = args.data

	# commands for data generation
	if dyna_flag:
		# instrument source
		cmd_instru = [compiler, '-fprofile-instr-generate', args.target, params, '-o', instru_dir+out_bin_name] + opt
		print(cmd_instru)
		# run executable
		cmd_run = ['LLVM_PROFILE_FILE="'+instru_dir+'a.profraw" '+instru_dir+out_bin_name+' '+input_data]
		# merger profile
		cmd_merge = ['llvm-profdata-9', 'merge', '-output='+instru_dir+'code.profdata', instru_dir+'a.profraw']
		# apply profile to generate bitcode
		cmd_bc = [compiler,'-c', '-g', '-fno-discard-value-names', '-emit-llvm', '-fprofile-instr-use='+instru_dir+'code.profdata', '-o', instru_dir+file_name+'.bc', args.target, params] + opt
	else:
		# collect branch info statically
		print("Params: ",params)
		cmd_bc = [compiler, '-c', '-g', '-fno-discard-value-names', '-emit-llvm', '-o', instru_dir+file_name+'.bc', args.target, params] + opt
		
	print("cmd_bc",cmd_bc)
	# generate data
	#'-disable-output'
	cmd_gen = ['~/libs/llvm-14-meliora/bin/opt', '-load', lib_path, '-cfggen', file_name+'.bc']
	###cmd_gen = ['opt-9', '-load', lib_path, '-cfggen', file_name+'.bc']
	print("cmd_gen",cmd_gen)
	
	# make new directory for instrumentation
	cmd_mkdir = ['mkdir', instru_dir]
	#print cmd_mkdir
	Command(cmd_mkdir).run('', shell=False)
	# timing
	t_start = time.time()

	if dyna_flag:
		print('start instrumentation...')
		Command(cmd_instru).run('', shell=False)
		print('start running executable...')
		Command(cmd_run).run('', shell=True)
		print('start merging...')
		Command(cmd_merge).run('', shell=False)
	else:
		print('Generating data statically ...')

	print('start generating bitcode...')
	Command(cmd_bc).run('', shell=True)
	print('start generating data')
	Command(cmd_gen).run('', cwd='./'+instru_dir, shell=True)
	print("INSTRU_dir",instru_dir)
	print("--CMG_GEN",cmd_gen)
	t_end = time.time()
	total_time = t_end - t_start
	print('done...')	
	print('time: {0} s'.format(total_time))
