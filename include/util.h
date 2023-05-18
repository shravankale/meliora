/*
 * Functions for extracting program metrics
 * Used as LLVM pass
 *
 * Kewen Meng
 *
 */


#ifndef UTIL_H
#define UTIL_H

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Analysis/MemoryDependenceAnalysis.h"
#include "llvm/Analysis/DependenceAnalysis.h"
#include "llvm/Analysis/LoopAccessAnalysis.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/ScalarEvolutionExpressions.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Constants.h"
#include "llvm/ADT/SCCIterator.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Format.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Hcfg.h"

using namespace llvm;
using namespace std;

// Get instructions from each block
// Return summary
bool getInstrMix(BasicBlock* bb, int* a) {
	// floating-point operation fadd, fmul, fdiv, fsub. index 0
	// memory operation read, write. index 1	
	// control operation, index 2
	// integer operation, index 3
	for (BasicBlock::iterator bi = bb -> begin(); bi != bb -> end(); ++bi) {
		Instruction &ins = *bi;
		//outs()<<ins.getOpcodeName()<<"\n";					

		// check vector instruction
		int vScale = 1;
		if (ins.getNumOperands() > 0)
		{
			Type* ty = ins.getOperand(0) -> getType();
			if (ty -> isVectorTy())
			{
                //Debugx changed from getVectorNumElements -> getStructNumElements()
				vScale = ty -> getStructNumElements();
			}
		}

		switch(ins.getOpcode()) {
			case Instruction::FAdd:
			case Instruction::FMul:
			case Instruction::FDiv:
			case Instruction::FSub:
					 a[0] += vScale; break;	
			case Instruction::Store:
			case Instruction::Load:
			case Instruction::Fence:
			case Instruction::GetElementPtr:
					 a[1] += vScale; break;
			case Instruction::Ret:
			case Instruction::Br:
			case Instruction::Switch:
			case Instruction::Resume:
					 a[2] += vScale; break;	
			case Instruction::Add:
			case Instruction::Mul:
			case Instruction::UDiv:
			case Instruction::SDiv:
			case Instruction::Sub:
					 a[3] += vScale; break;	
			default: break;
		}

	}

	return true;
}

// parse getElementPtr instruction
// return array name
string getArrayName(Value* v) {
 
    bool delFlag = false;
    GetElementPtrInst* ptrIns; 
    // it is possible to take getElementPtrConstantExpr obj
    // here rather than an instruction
    // so test it first
    if (isa<ConstantExpr>(v)) {
        // Note this parentless instruction should be removed after use
        // otherwise llvm verifier fails
        Instruction* i = dyn_cast<ConstantExpr>(v) -> getAsInstruction();
        ptrIns = dyn_cast<GetElementPtrInst>(i);
        delFlag = true;
    } else {
        ptrIns = dyn_cast<GetElementPtrInst>(v);
    }
    Value* ptrInsOpr = ptrIns -> getPointerOperand();
    string arrayName;
    
    if (isa<LoadInst>(ptrInsOpr)) {
        LoadInst* loadIns = dyn_cast<LoadInst>(ptrInsOpr);
        Value* loadOpr = loadIns -> getPointerOperand();
        arrayName = (loadOpr -> getName()).str(); 

    } else if (isa<GetElementPtrInst>(ptrInsOpr)){ 
        // for 2d array the pointer operand is
        // a getElementPtr instruction
        GetElementPtrInst* getEPIns = dyn_cast<GetElementPtrInst>(ptrInsOpr);
        Value* getEPOpr = getEPIns -> getPointerOperand();
        arrayName = (getEPOpr -> getName()).str(); 
    } 

    if (delFlag) {
       delete ptrIns; 
    }
    return arrayName;
}


void updateHist(Value* v, unordered_map<string, uint64_t>& varMap, 
                    DataLayout* dataLayout, uint64_t& totalBytes,
                        vector<int>& binRange, vector<int>& bucket) {

    // get variable name
    string stName;
    // if access array 
    if (isa<GEPOperator>(v)) {
        stName = getArrayName(v);
    } else {
        stName = (v -> getName()).str();
    }

    // get size
    PointerType* ptrType = dyn_cast<PointerType>(v->getType());
    uint64_t accessSize = dataLayout -> getTypeStoreSize(ptrType->getPointerElementType());
    // update tracker
    totalBytes += accessSize;        

    if (!stName.empty()) {
        if (varMap.find(stName) != varMap.end()) {
            // not first occurence
            uint64_t dist = totalBytes - varMap[stName];        
            //outs()<<"variable: " << stName << " dist " << dist << "\n";
            // update histogram 
            for (int i = 0; i < binRange.size() - 1; i ++) {
                if (dist >= binRange[i] && dist < binRange[i + 1]){
                    bucket[i]++;
                    break;
                }
            }               
        }
        // update  
        varMap[stName] = totalBytes;
    }
}

// Function to analyze the distance between reuse
// of an variable
void getDistance(BasicBlock* bb, Loop* loop, DataLayout* dataLayout, 
                    vector<int>& binRange, vector<int>& bucket) {
    // keep track of bytes accessed in total
    uint64_t totalBytes = 0;
    Value* prevGetPtr = NULL;
    // consider each getElementPtr access unique array element
    bool isUniqueAccess = true;
    unordered_map<string, uint64_t> varMap; 
    
    //std::cout<<"Inside getDistance()"<<endl;

	for (BasicBlock::iterator bi = bb -> begin(); bi != bb -> end(); ++bi) {
		Instruction& ins = *bi;

        if (isa<StoreInst>(ins)) {
            // store instruction
            StoreInst* storeIns = dyn_cast<StoreInst>(&ins);
            Value* v = storeIns -> getPointerOperand();

            //std::cout<<"getDistance()/store_instruction: "<<v->print()<<endl;

            updateHist(v, varMap, dataLayout, totalBytes, binRange, bucket); 
            
            
        } else if (isa<LoadInst>(ins)){
            // load instruction
            LoadInst& loadIns = cast<LoadInst>(ins);
            Value* v = loadIns.getPointerOperand();

            //std::cout<<"getDistance()/load_instruction: "<<endl;

            updateHist(v, varMap, dataLayout, totalBytes, binRange, bucket); 
        }
        
        /* 
        else if (isa<GetElementPtrInst>(ins)) {
            for (auto op = ins.op_begin(); op != ins.op_end(); op++) {
                Value* v = op->get();
                StringRef name = v->getName();
                outs() << "Get ptr: " << name << "\n";
            }
            GetElementPtrInst* ptrIns = dyn_cast<GetElementPtrInst>(&ins);
            Value* v = ptrIns -> getPointerOperand();
            Value* vOpr = ptrIns -> getOperand(1); 
            PointerType* ptrType = dyn_cast<PointerType>(v->getType());
            uint64_t storeSize = dataLayout -> getTypeStoreSize(ptrType->getPointerElementType());
            outs() << "get element ptr size: " << storeSize << "\n";
            //outs()<<"test: " << *se.getSCEVAtScope(vOpr, loop)<<"\n";
            if (isa<LoadInst>(v)) {
                // cast to load instruction
                LoadInst* loadIns = dyn_cast<LoadInst>(v);
                // get index variable
                // e.g a.addr
                Value* loadOpr = loadIns -> getPointerOperand();
                outs() << "index: " << loadOpr -> getName() << "\n";
            }
            prevIns = true;
        }*/
    }   
}

// get input file name from Function instance
string getBaseName(Function& F) {

	string baseOutName;

	DISubprogram* dis = F.getSubprogram();
	if (dis){
		string temp = dis->getFilename().str();
		baseOutName = temp.substr(temp.find_last_of("/")+1);
	} 

	return baseOutName;
}


// Get loop induction variable
// Note the llvm function Loop::getInductionVariable
// requires the simplified form of loop
// PhiNode and SCEVAddRecExpr may not work with -O0
// the workaround here is to get loop condition and 
// test the load instruction to get induction variable
string getIdv(Loop* l) {
    //std::cout<<"Inside getIDV"<<endl;
    string ret;
    for (BasicBlock::iterator it = l->getHeader()->begin(); it != l->getHeader()->end(); it++) {
        Instruction& ins = *it;
        if (isa<LoadInst>(ins)) {
            LoadInst* loadIns = dyn_cast<LoadInst>(&ins);
            Value* v = loadIns -> getPointerOperand(); 

            //std::cout<<"Value* v "<<v->getName().str()<<endl;

            if (v != NULL) {
                if (!v -> getName().empty()) {
                    ret = v->getName().str();
                    break;  
                }
                
            }
        } 
        
    }

    return ret;
    
}
/* Temp checkfix
int checkSkip(Loop* l) {

    std::cout<<"Inside checkSkip()"<<endl;

    int ret = 2;
   
    string name = getIdv(l);
    std::cout<<"Loop Induction variable: "<<name<<endl;
    if (!name.empty()) {
        // check two pre set variables
        if (name == "orio_i" || name == "_t") {
            ret = 1;
       // } else if (name.substr(0, 5) != "loop_") {
        }else {
            // check fake loop induction variable 
            ret = 2;
        }   
    }
    std::cout<<"RET: "<<ret<<endl;
    std::cout<<"Exiting checkSkip()"<<endl;
    return ret;
}*/

// check whether to skip current loop
// based on loop induction variable
// return: 0 - skip this loop (or nested loop)
//         1 - Orio generated outer loop (orio_i, _t)
//         2 - target to process
int checkSkip(Loop* l) {

    //std::cout<<"Inside checkSkip()"<<endl;

    int ret = 0;
   
    //Can also get string name via l->getName().str()
    string name = getIdv(l);
    
    std::cout<<"Loop Induction variable: "<<name<<endl;
    if (!name.empty()) {
        // check two pre set variables
        if (name == "orio_i" || name == "_t") {
            ret = 1;
        } 
        else if (name.substr(0, 5) == "loop_") {
            // check fake loop induction variable 
            ret = 2;
        }
        
    }
    std::cout<<"RET: "<<ret<<endl;
    //std::cout<<"Exiting checkSkip()"<<endl;
    return ret;
}

// Get the innermost loop of the target nested loops
Loop* getInnerLoop(Loop* lp) {
    //std::cout<<"Inside getInnerLoops()"<<endl;
    stack<Loop*> stk;
    Loop* ret;
    stk.push(lp);    

    while(!stk.empty()) {
        Loop* loop = stk.top();
        stk.pop();

        vector<Loop*> subLoops = loop->getSubLoops();                 
        if (subLoops.size() !=0) {
            stk.push(subLoops.front());
        } else {
            // innermost loop
            ret = loop;
        }
    }
    //std::cout<<"Exiting getInnerLoops()"<<endl;
    return ret;
}

// Get all candidate loops 
// which are enclosed by loops (labeling) whose
// induction variables are loop_xxx
// Skip the fake loop header, and because Orio
// generates a identical loop to ensure the unrolling
// index can be divided, so only keep the 
// first loop for unrolling, for example
// 10 for (int loop_10=0; loop_10 < 1; loop_10++)
// 11   for () 
// 12    for () 
// 13   for () <- identical loop to line 11
// 14    for ()
// This function returns the nested loop (innermost) from line 11
// and skips the loop at line 13

//In use
void getTargetLoops(LoopInfo& li, vector<Loop*>& loopVec) {

    //std::cout<<"Inside getTargetLoops()"<<endl;
    
    for (LoopInfo::iterator it = li.begin(); it != li.end(); it++) {
        Loop* loop = *it;
        stack<Loop*> stk;
        stk.push(loop);

        while (!stk.empty()) {
            Loop* lp = stk.top();
            stk.pop();
            
            int isTarget = checkSkip(lp);

            std::cout<<"isTarget loop? "<<isTarget<<endl;
            //0 - skip this loop (or nested loop)
            if (isTarget != 0) {
                //1 - Orio generated outer loop (orio_i, _t)
                if (isTarget == 1) {
                    // skip this loop
                    for (LoopInfo::iterator subIt = lp->getSubLoops().begin(); 
                            subIt != lp->getSubLoops().end(); subIt++) {
                        stk.push(*subIt);
                    }
                } 
                //2 - target to process
                if (isTarget == 2) {
                    // store the loop
                    loopVec.push_back(getInnerLoop(lp));
                }
            } 
        }
    }
    //std::cout<<"Exiting getTargetLoops()"<<endl;
}
//Used for li_ps
void getTargetLoops(LoopInfo* li, vector<Loop*>& loopVec) {

    //std::cout<<"Inside getTargetLoops()"<<endl;
    
    for (LoopInfo::iterator it = li->begin(); it != li->end(); it++) {
        Loop* loop = *it;
        stack<Loop*> stk;
        stk.push(loop);

        while (!stk.empty()) {
            Loop* lp = stk.top();
            stk.pop();
            
            int isTarget = checkSkip(lp);

            std::cout<<"isTarget loop? "<<isTarget<<endl;

            if (isTarget != 0) {
                if (isTarget == 1) {
                    // skip this loop
                    for (LoopInfo::iterator subIt = lp->getSubLoops().begin(); 
                            subIt != lp->getSubLoops().end(); subIt++) {
                        stk.push(*subIt);
                    }
                } 
                
                if (isTarget == 2) {
                    // store the loop
                    loopVec.push_back(getInnerLoop(lp));
                }
            } 
        }
    }
    //std::cout<<"Exiting getTargetLoops()"<<endl;
}


// Function for write CFG info to file
// Each loop within the function generates an output
// Params:
//		li   - LoopInfo
//		BPI  - BranchProbability
//		F    - Function info 
//      mode - output mode
//			   0 : matrix only
//			   1 : dot file only
//baseOutName.loop_ll@lpCtr
//Check funcName

Hcfg writeToFile(Function& F, LoopInfo& li, DataLayout* layout, 
                    const BranchProbabilityInfo* BPI, 
                    vector<int>& binConfig,
                    ScalarEvolution& se, Hcfg h, int mode=0) 
{

    std::cout<<"_____________INSIDE UTIL.H_____________"<<endl;

	string baseOutName = getBaseName(F);
	string funcName	   = F.getName().str();
    //using namespace std;
    std::cout << "baseOutName" << baseOutName << endl;
    std::cout << "baseOutName2" << baseOutName << endl;
    h.file_name.append(baseOutName);

    /*
    ofstream outfile;
    outfile.open("/home/users/shravank/projects/meliora/example/mm/mylog.txt", ios::app);
    outfile << "V1 - baseOutName" << baseOutName << endl;
    outfile.close();
    */

    /*std::ofstream ofs;
    ofs.open ("/home/users/shravank/projects/meliora/example/mm/mylog.txt", std::ofstream::out | std::ofstream::app);

    ofs << "V1 - baseOutName" << baseOutName << endl;

    ofs.close();*/

	// hash map as lookup table for 
	// basic block and its id
	unordered_map <BlockAddress*, int> bbMap;
    vector<Loop*> loopVec;

    // get candidate loops
    getTargetLoops(li, loopVec);


    // track the order of a loop in the src
    // adapt to post-order 
    int lpCtr = loopVec.size();
    std::cout<<"loopVec Size: "<<lpCtr<<endl;
    // Note LoopInfo ONLY returns top-level loop for nested loops
	for (LoopInfo::iterator lp = loopVec.begin(); lp != loopVec.end(); lp++)
	{

		Loop *loop = *lp;
        llvm::outs()<<"-------Filtered Candidate Loops: "<<getIdv(loop)<<"\n";
        
		// find outermost loop
		// if (loop -> getParentLoop() != NULL) continue;
								
		// output name for each loop
		string outFileName = baseOutName;
        std::cout << "baseOutName2" << baseOutName << endl;

		DebugLoc sline = loop -> getStartLoc();
		string ll;
		if (sline)
		{
            std::cout<<"Inside sline"<<endl;
			ll = to_string(sline.getLine());
			outs() << "Loop starts at line: " << ll <<"\n";
            //HCFG - Loop ID
            h.loop_id = ll;
            //string loopLabel = getIdv(loop);
            outFileName.append(".loop_"+ll);
            outFileName.append("@"+to_string(lpCtr));

            //HCFG - Loop order
            h.loop_cntrl = to_string(lpCtr);

			if (mode == 0) {
				outFileName.append(".matrix");
			} else {
				outFileName.append(".dot");
			}

			lpCtr--;
		}	
		// outstream
		error_code RC;
        //Debugx LLVM 14 change
		//raw_fd_ostream out(StringRef(outFileName), RC, sys::fs::OpenFlags::F_None);
        raw_fd_ostream out(StringRef(outFileName), RC, sys::fs::OpenFlags::OF_None);


		/*string testOutFile = outFileName;
		testOutFile.append(".txt");
		raw_fd_ostream tout(StringRef(testOutFile), RC, sys::fs::OpenFlags::F_None);
		tout << 5;
		tout.flush();
		tout.close();
        */

		//raw_fd_ostream out(StringRef(outFileName), RC, sys::fs::F_None);


		// TODO add new metrics to dot
		if (mode == 1) {
			// write dot file head
			out << "digraph \"CFG for loop in function \'" << funcName << "\' at line " << ll << "\" {\n";
			out << "\tlabel = " << "\"CFG for loop in function \'" << funcName << "\' at line " << ll << "\";\n\n";
		}

        // skip basic blocks of the fake loop
        /*
        BlockAddress *addrHeader = BlockAddress::get(loop->getHeader());
        BlockAddress *addrLatch = BlockAddress::get(loop->getLoopLatch());
        // get the two intermediate successors of loop header
        const Instruction *termIns = loop->getHeader()->getTerminator();        
        BlockAddress *addrT = BlockAddress::get(termIns->getSuccessor(0));
        BlockAddress *addrF = BlockAddress::get(termIns->getSuccessor(1));
        */
    
		// label each block as id within the loop
		// start from 0
		int label = 0;
		for (Loop::block_iterator bi = loop -> block_begin(); bi != loop -> block_end(); bi++)
		{
			//(*bi)->printAsOperand(outs(),false);
			// create a mapping
            /*
            BlockAddress *bAddr = BlockAddress::get(*bi);
            if (bAddr == addrHeader || bAddr == addrLatch || bAddr == addrT || bAddr == addrF) {
                bbMap[BlockAddress::get(*bi)] = -1;
            } else {
                bbMap[BlockAddress::get(*bi)] = label++;
            }
            */

            //std::cout<<"Inside Loop::Block_iterator"<<endl;
         
            bbMap[BlockAddress::get(*bi)] = label++;
			
			// setName not working here 
			// since it doesn't allow duplicate name
			//(*bi) -> setName(Twine(label));
			//int pid;
			// ((*bi) -> getName()).getAsInteger(10, pid);
		}
		float* matrix;
		if (mode == 0) {
		   matrix = new float[label*label];
		   for (int i = 0; i < label; i++)
			   for (int j = 0; j < label; j++) {	
				   matrix[i*label + j] = 0.0f;
		   }
		 

		   
		}
	
		// storage for instruction mix for each basic block
        // added loop depth for each bb
        // added distance vector 
        // the format is [instruction x 4, depth, histogram x 5]
		vector<vector<float>> nodeInstr(label, vector<float>(5+binConfig.size()-1, 0));

		for (Loop::block_iterator bi = (loop -> block_begin()); bi != loop -> block_end(); bi++)
		{
			BasicBlock* bb = *bi;				
			BlockAddress* bAddr = BlockAddress::get(bb);
			// label(id) for current basic block
			int pid = bbMap[bAddr];

            std::cout<<"Basic Block PID was skipped: "<<pid<<endl;
            
            // skip 
            if (pid == -1) {
                continue;
            }

			int mix[4] = {0};
            vector<int> hist(binConfig.size()-1, 0);
			getInstrMix(bb, mix); 
            getDistance(bb, loop, layout, binConfig, hist);
            
            // get loop depth for this bb
            int loopLvl = li.getLoopDepth(bb); 
            
			if (mode == 1) {
				// write node info
				//out << "\t" << (bb->getName()).str() <<" [shape=record,label=\"{";
				out << "\t" << to_string(pid) <<" [shape=record,label=\"{";
				out << to_string(pid) << ":\\l FLOP: " << mix[0] << "\\l IntOp: " << mix[3] <<"\\l MemOp: " << mix[1] << "\\l CtrlOp: " << mix[2] << "\\l";
			}
            // llvm 9 removed TerminatorInst
			//const TerminatorInst *tInst = bb -> getTerminator();
			const Instruction *tInst = bb -> getTerminator();
			unsigned numSucc = tInst -> getNumSuccessors();
			
			//int pid;
			// parent (current) bb id 
			//((*bi) -> getName()).getAsInteger(10, pid);

			// get instruction mix for node
            float totInstr = mix[0] + mix[1] + mix[2] + mix[3];
            if (totInstr == 0) {
                totInstr = 1;
            }
            nodeInstr[pid][0] = mix[0] / totInstr;
            nodeInstr[pid][1] = mix[1] / totInstr;
            nodeInstr[pid][2] = mix[2] / totInstr;
            nodeInstr[pid][3] = mix[3] / totInstr;
            // add loop depth
            nodeInstr[pid][4] = loopLvl; 
            // add other node metrics
            // distance vector
            float totHist = hist[0] + hist[1] + hist[2] + hist[3] + hist[4];
            if (totHist == 0) {
                totHist = 1;
            }
            for (int i = 5; i < nodeInstr[0].size(); i++) {
                nodeInstr[pid][i] = hist[i-5] / totHist;
            }

			if (numSucc == 0) 
			{
				if (mode == 1) {
					// no child, close node info here
					out << "}\"];\n";
				}	
			}

			if (numSucc > 0)
			{

				if (numSucc == 1)
				{
					// has only one child
					// child bb id
					int cid = bbMap[BlockAddress::get(tInst->getSuccessor(0))];
					// (tInst -> getSuccessor(0) -> getName()).getAsInteger(10, cid);
                    if (cid == -1) {
                        continue;
                    }	

					if (mode == 1) {
						// close node info, add edge info
						out << "}\"];\n";
						out << "\t" << to_string(pid) << " -> " << to_string(cid);
						// edge weight is 1.00
						out <<" [label = \"1.00\"];\n";
					} else {
						matrix[pid * label + cid] = 1.0f;
					}
	
				} else {
					// process branch	
					// assume two branch at most for now
					//int cid;
					
					if (mode == 1) {
						// close node info
						out <<"|{<s0>T|<s1>F}}\"];\n";
					}

					for (unsigned i = 0; i < numSucc; i++) {
						BasicBlock *succBB = tInst->getSuccessor(i);
						BranchProbability bp = BPI->getEdgeProbability(bb, succBB);	
						//succBB->printAsOperand(outs(),false);
						float value = rint((float)bp.getNumerator()/bp.getDenominator()*100)/100;
						//(succBB -> getName()).getAsInteger(10, cid);
						int cid = bbMap[BlockAddress::get(succBB)];
                            
                        if (cid == -1) {
                            continue;
                        }
		
						if (mode == 0) {
							matrix[pid * label + cid] = value;
						} else {
							// write edge
							// for the loop head we need to create a fake node 
							// to represent the node outside loop to complete branch
							string succName = to_string(cid);
							if (succName.empty())
							{
								out << "\t" << to_string(pid) << ":s" << i << " -> outside";
								out << " [label =\"" << value << "\"];\n";
								// create an outside node
								out << "\toutside [shape=record,label=\"outside loop\"];\n";

							} else {
								out << "\t" << to_string(pid) << ":s" << i << " -> " << to_string(cid);
								out << " [label =\"" << value << "\"];\n";
							}
						}	
					}

				}	

			}	
		}

        std::cout << "__________Not Writing Matrix ___________"<< endl;
        //You have the outfile name, .matrix in terms of nodeInste
        string matrixOut = "";
		if (mode == 0) {

            std::cout << "..........Writing Matrix .........."<< endl;
            
            // write matrix	
            // first line of the output file is the matrix size
            out << label <<"\n";
            matrixOut = matrixOut + std::to_string(label) + '\n';
            for (int i = 0; i < label; i++) {

				// write instruction mix for the node
				// in the beginning of the line
				// write all node metrics
                for (int k = 0; k < nodeInstr[0].size(); k++) {
                    if (k == 4) {
                        // loop depth
                        out << format("%.2f", nodeInstr[i][k]);

                        float x = (float)nodeInstr[i][k];
                        std::stringstream st;
                        st << std::fixed << std::setprecision(2)<< x;
                        matrixOut = matrixOut.append(st.str());
                        h.body.append(st.str());
                        
                        
                    } else {
                        out << format("%.2f", nodeInstr[i][k]*100);
                        
                        float x = (float)nodeInstr[i][k]*100;
                        std::stringstream st;
                        st << std::fixed << std::setprecision(2)<< x;
                        matrixOut = matrixOut.append(st.str());
                        h.body.append(st.str());
                    }
                    if (k != nodeInstr[0].size()-1){
                        out << ":";
                        matrixOut = matrixOut + ":";
                        h.body.append(":");
                    } else {
                        out <<"\t";
                        matrixOut = matrixOut + "\t";
                        h.body.append("\t");
                    }
                }
							
				for (int j = 0; j < label; j++) {	
					out << format("%.2f", matrix[i*label + j]) << "\t";

                    float x = (float)matrix[i*label + j];
                    std::stringstream st;
                    st << std::fixed << std::setprecision(2)<< x;
                    matrixOut = matrixOut.append(st.str());
                    h.body.append(st.str());

                    matrixOut = matrixOut.append("\t");
                    h.body.append("\t");
				}	
				out <<"\n";
                matrixOut = matrixOut + "\n";
                h.body.append("\n");
			}

			delete[] matrix;
		
		} else {
			out<<"}";
            std::cout<<"Mode set to dot file mode"<<endl;
            
		}
        //std::cout <<"out"<<out<<endl;
        std::cout <<"File Name: " << outFileName << endl;
        std::cout << "Matrix Out: " << matrixOut << endl;
        //h.body.append(matrixOut);

		// close stream
		out.flush();
		out.close();

	}// end for 
    
std::cout<<"h.kernel_name"<<h.kernel_name<<endl;
std::cout<<"_____________ENDOF UTIL.H_____________"<<endl;
return h;
}//end method



#endif
