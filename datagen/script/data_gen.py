import os
import re
import sys

'''
Proccess and generate appropriate data format 
for model training

state.log is used for keep track of the last states of
proccessed data so that it is able to automatically label
the new data

@Kewen Meng
 
'''
# TODO try catch block

class DataGenerator():
    '''
    The data generator used for parsing the output from llvm pass (Orio postprocess)
    to generate the graph data for further analysis (e.g. embedding, classfication)
    '''
    def __init__(self, path):
        # get the current index of node, graph and current graph class 
        self.node_num, self.graph_num, self.graph_class = self.__read_log()
        # target directory
        self.dir_path = path    
        # node label
        self.nl = ['Flop', 'Mem', 'Ctrl', 'Int']
        self.__get_file_handler()
        

    def __read_log(self):
        '''
        Read log file to keep track of the parameters for the input of graph framework
        Parameters: number of node, number of graph, number of class
        '''
        try:
            with open('state.log', 'r+') as f:
                line = f.readline()
        except IOError:
            with open('state.log', 'w'): pass
            return 1, 1, 1  
    
        # parse the line 
        return map(int, re.split(r'\t+', line))

    def __write_log(self):
        '''
        Keep the state of three parameters in the log file
        '''
        with open('state.log', 'w') as f:
            f.write(str(self.node_num) + '\t' + str(self.graph_num) + '\t' + str(self.graph_class))

            
    def __iter_dir(self):
        # assume test case locates in a/b/c/src/
        # get src name
        src_name = os.path.basename(os.path.normpath(self.dir_path))
        for file_name in os.listdir(self.dir_path):
            if file_name.endswith('.temp'):
                # Temporary workaround for processing splitted loops data
                # TODO maybe we can have this as an argument
                skip_num = 0
                process_num = 20
                # temp directory
                sub_dir = self.dir_path + '/' + file_name 
                # get test version, hardcoded here
                # e.g __orio_perftest7.c.temp -> 7
                # will not work for non Orio generate data
                #ver = file_name[15:file_name.find('.')]
                
                # get test name: name + version
                # e.g jocobi20
                #test_name = src_name + ver
                # use to differentiate graph generate from same src
                # jacobi7_2 means second graph from jacobi7 test
                # graph_counter = 1
                for sub_name in os.listdir(sub_dir):
                    # skip validate.c.xx.matrix
                    if "validation." in sub_name:
                        continue
                   
                    if process_num == 0:
                        break
                    
                    if sub_name.endswith('.matrix'): 
                        if skip_num != 0:
                            skip_num -= 1
                            continue
                        # find matrix file
                        # each matrix is a graph
                        target_file = sub_dir+'/'+sub_name
                        if os.stat(target_file).st_size !=0:
                            # avoid empty file
                            print(sub_name+'\n')
                            test_name = src_name + '_' + sub_name[0:sub_name.rfind('.')]
                            #self.__process_matrix(target_file, test_name+'_'+str(graph_counter))
                            self.__process_matrix(target_file, test_name)
                            self.graph_num += 1
                            process_num -= 1
                            #graph_counter += 1
        # iter over all graphs of the same class
        self.graph_class += 1

    def __process_matrix(self, file_path, graph_id=''):
        # parse the .matrix file to get data

        base_node_idx = self.node_num
        base_graph_idx = self.graph_num
        with open(file_path, 'r') as f:
            # first line flag
            fl_flag = False
            # list of list for storing node attributes
            node_attr = []
            for line in f:
                if not fl_flag:
                    # first line
                    mat_size = int(line)
                    fl_flag = True
                    # list for storing inbound edge weight
                    edge_w = [0.0] * mat_size
                else:
                    line_value = re.split(r'\t+', line.rstrip())
                    edge_list = line_value[1:]  
                    # output edge
                    e_idx = self.node_num
                    for e in edge_list:
                        if float(e) != 0:
                            # into whole graph file 
                            self.graph_hdlr.write(str(base_node_idx) + ', ' + str(e_idx) + '\n')                    
                    
                            # into edge attribute file
                            self.edge_attr_hdlr.write(e + '\n')
                            # record inbound edge weight
                            edge_w[e_idx-self.node_num] += float(e)
                        #update idx
                        e_idx += 1

                    # ouput node
                    instr_cnt = re.split(r':+', line_value[0])
                    instr_list = map(int, instr_cnt)
                    # decide node label
                    node_label = instr_list.index(max(instr_list))  
                    self.node_label_hdlr.write(str(node_label) + '\n')
                    # since we combine the edge weight with node attribute
                    # not output here, instead save the attributes
                    #self.node_attr_hdlr.write(', '.join(instr_cnt) + '\n')
                    node_attr.append(instr_cnt)
                    # output graph
                    self.graph_indi_hdlr.write(str(base_graph_idx)+'\n')    

                    base_node_idx += 1  
            # end line loop
            self.node_num = base_node_idx
            self.graph_label_hdlr.write(str(self.graph_class) + '\n')   
            self.graph_id_hdlr.write(graph_id + '\n')   
            # write node attribute before moving to next matrix
            self.__edge_to_node(node_attr, edge_w)          


    def __edge_to_node(self, node_attr, edge_attr):
        # set the edge transition probability as a node attribute (last one) 
        for i in range(len(edge_attr)):
            self.node_attr_hdlr.write(', '.join(node_attr[i]) + ', ' + str(edge_attr[i]) + '\n')


    def __get_file_handler(self):
        # return file handlers to append
        self.graph_hdlr = open('CFG_A.txt', 'a')
        self.graph_indi_hdlr = open('CFG_graph_indicator.txt', 'a')
        self.graph_label_hdlr = open('CFG_graph_labels.txt', 'a')
        self.node_attr_hdlr = open('CFG_node_attributes.txt', 'a')
        self.node_label_hdlr = open('CFG_node_labels.txt', 'a')
        self.edge_attr_hdlr = open('CFG_edge_attributes.txt', 'a')
        self.graph_id_hdlr = open('CFG_graph_id.txt', 'a')

    def __close_file(self):
        # close opened file
        self.graph_hdlr.close()
        self.graph_indi_hdlr.close()
        self.graph_label_hdlr.close()
        self.node_attr_hdlr.close()
        self.node_label_hdlr.close()
        self.edge_attr_hdlr.close()
        self.graph_id_hdlr.close()

    def generate(self):
        self.__iter_dir()
        self.__close_file()
        self.__write_log()

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print ('Please provide target directory, exit...')
        sys.exit(0)
    DataGenerator(sys.argv[1]).generate()
