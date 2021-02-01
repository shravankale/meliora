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
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/ADT/SCCIterator.h"
#include "llvm/ADT/StringRef.h"
#include <unordered_set>
#include "util.h"

using namespace llvm;
using namespace std;

// inline functions

namespace {
	struct CfgPass : public FunctionPass {
		static char ID;
		CfgPass() : FunctionPass(ID) {}

	virtual void getAnalysisUsage(AnalysisUsage &AU) const
	{
		//AU.addRequired<DependenceAnalysisWrapperPass>();
		AU.addRequired<LoopAccessLegacyAnalysis>();
		AU.addRequired<LoopInfoWrapperPass>();
		AU.addRequired<MemoryDependenceWrapperPass>();
		AU.addRequired<DependenceAnalysisWrapperPass>();
		AU.addRequired<BlockFrequencyInfoWrapperPass>();
		AU.addRequired<ScalarEvolutionWrapperPass>();
		AU.setPreservesAll();
	}

	
    virtual bool runOnFunction(Function &F) {

        Module* module = F.getParent();
        DataLayout* layout = new DataLayout(module);
		string funcName	= F.getName().str();
		// skip Orio input function
		if (funcName == "malloc_arrays") return false;
		if (funcName == "init_input_vars") return false;
  
        // histogram config
        vector<int> binConfig = {5, 9, 33, 65};
        // extend the range to 0, ..., MAX
        binConfig.insert(binConfig.begin(), 0);
        binConfig.push_back(INT_MAX);
        /*
        outs() << "Buckets are: \n";
        for (int i = 0; i < binConfig.size()-1; i++){
            if (i != binConfig.size()-2) {
                outs() << "[" << binConfig[i] << ", "<<binConfig[i+1] << ") ";
            } else {
                outs() << "[" << binConfig[i] << ", INT_MAX)";
            }
        }
        */

		LoopInfo &li = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
		MemoryDependenceWrapperPass &mdwp = getAnalysis<MemoryDependenceWrapperPass>();
		LoopAccessLegacyAnalysis &lala = getAnalysis<LoopAccessLegacyAnalysis>();
		DependenceInfo &depInfo = getAnalysis<DependenceAnalysisWrapperPass>().getDI();
		ScalarEvolution &se = getAnalysis<ScalarEvolutionWrapperPass>().getSE();
		auto &mdr = mdwp.getMemDep();

		// get branch weights
		BlockFrequencyInfo &BFI = getAnalysis<BlockFrequencyInfoWrapperPass>().getBFI();
		//BFI.print(outs());
		const BranchProbabilityInfo *BPI = BFI.getBPI();
		//BPI->print(outs());
		/*	
		for (inst_iterator I = inst_begin(F), E = inst_end(F); I != E; I++)
			for (inst_iterator J = I; J != E; J++){
				auto infoPtr = depInfo.depends(&*I, &*J, true);
				if (infoPtr != NULL)
				infoPtr->dump(errs());
			}	
		*/

		writeToFile(F, li, layout, BPI, binConfig, se, 0);		

		
		/*
		outs() << "SCCs for " << F.getName() << " in post-order:\n";
		for (scc_iterator<Function *> I = scc_begin(&F),
				IE = scc_end(&F);
				I != IE; ++I) {
			// Obtain the vector of BBs in this SCC and print it out.
			const std::vector<BasicBlock *> &SCCBBs = *I;
			outs() << "  SCC: ";
			for (std::vector<BasicBlock *>::const_iterator BBI = SCCBBs.begin(),
					BBIE = SCCBBs.end();
					BBI != BBIE; ++BBI) {
				outs() << (*BBI)->getName() << "  ";

			}
			outs() << "\n";

		}	
		*/	
	
		/*	
		// instruction mix
		for (Function::iterator fi = F.begin(); fi != F.end(); fi++)
		{
			BasicBlock &bb = *fi;
			bb.setName(Twine(1));
			outs()<<"bb id: ";
			bb.printAsOperand(outs(),false);
			outs()<<"\n";
			// define instruction counters
			int cntMemOp = 0;
			int cntVec = 0;
			// iterate instructions
			for (BasicBlock::iterator bi = bb.begin(); bi != bb.end(); bi++) {
				Instruction &ins = *bi;
				//outs()<<ins.getOpcodeName()<<"\n";					
				if (ins.mayReadOrWriteMemory()) 
				{
					cntMemOp++;
				}
				
				if (ins.getNumOperands() > 0)
				{
					if (ins.getOperand(0)->getType()->isVectorTy())
					{
						outs()<<ins.getOpcodeName()<<"\n";
						outs()<<"type ";
						ins.getType()->print(outs());
						cntVec++;
					}
				}
			}

			outs() << "============== stats ============"<<"\n";
			outs() << "Memory instruction: " << cntMemOp << "\n";
			outs() << "Vector instruction: " << cntVec << "\n";
			outs() << "================================="<<"\n\n";
			
		}
		*/
		
        delete layout;

		return false;
	}

  };
}

char CfgPass::ID = 0;

/*
// In this way we can directly use clang to load the dynamic library
// e.g clang++-3.9 -Xclang -load -Xclang pass/libCfgPass.so ../test/HelloWorld.C
 
static void registerCfgPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
	PM.add(new MemoryDependenceWrapperPass());
	PM.add(new LoopAccessLegacyAnalysis());
	PM.add(new CfgPass());
}
static RegisterStandardPasses
  RegisterCfgPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerCfgPass);
*/

// In this way we should use opt to load the dynamic library and apply to the llvm bitcode
// e.g clang-3.9 -c -emit-llvm ../test/HelloWorld.C -o HelloWorld.bc
// opt-3.9 -mem2reg -loop-simplify -loop-rotate -load cfgpass/libCfgPass.so -cfggen -disable-output HelloWorld.bc
static RegisterPass<CfgPass> X("cfggen", "test for using the existing pass",
									"false",
									"true");
