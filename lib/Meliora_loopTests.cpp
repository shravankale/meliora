#include "Meliora.h"
#include "isl_domsched2pattern.h"
//#include "llvm/ADT/Statistic.h"
#include "llvm/Support/Debug.h"
//For printing to standard out
#include "llvm/Support/raw_ostream.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
//Instruction iterator for polly::ScopStmt
#include "llvm/IR/InstIterator.h"
//Using llvm::ArrayRef<T>
#include "llvm/ADT/ArrayRef.h"

//Required Analysis
#include "llvm/Analysis/LoopInfo.h" //&li
#include "llvm/Analysis/LoopAccessAnalysis.h"
#include "llvm/Analysis/BlockFrequencyInfo.h" //BPI
#include "llvm/Analysis/ScalarEvolution.h" //se

//Polly
#include "polly/PolyhedralInfo.h"
//#include "polly/isl/set.h"
//#include "polly/isl/isl-noexceptions.h"
#include "polly/ScopInfo.h"

//Include custom meliora
#include "Hcfg.h"
#include "util.h"

#include "iostream"
#include <string>
#include <unordered_set>
#include <typeinfo>

//Boost Inclusions
//#include "boost/python/detail/wrap_python.hpp"

#include <boost/python.hpp>
#include <boost/filesystem.hpp>
#include <Python.h>

//Boost namespace
using namespace boost;
using namespace boost::python;


using namespace llvm;
using namespace std;
using namespace polly;
//using namespace isl;

using namespace isl_ItSpace;

#define DEBUG_TYPE "Meliora_DEBUG"

//STATISTIC(NumOfInst, "Number of Instructions.");
//STATISTIC(NumOfBB, "Number of basic blocks.");

PreservedAnalyses MelioraPass::run(Function &F, FunctionAnalysisManager &AM){

    std::cout<<"Inside run function"<<endl;

    Module* module = F.getParent();
    DataLayout* layout = new DataLayout(module);

    // histogram config
	vector<int> binConfig = {5, 9, 33, 65};
	// extend the range to 0, ..., MAX
	binConfig.insert(binConfig.begin(), 0);
	binConfig.push_back(INT_MAX);

    //Analysis Required for Meliora
    LoopInfo &li = AM.getResult<LoopAnalysis>(F);
    BlockFrequencyInfo &BFI = AM.getResult<BlockFrequencyAnalysis>(F);
    const BranchProbabilityInfo *BPI = BFI.getBPI();
    ScalarEvolution &se = AM.getResult<ScalarEvolutionAnalysis>(F);
    //Polly
    ScopInfo &si = AM.getResult<ScopInfoAnalysis>(F);

    //Container for hcfgs
	struct Hcfg hcfg_obj;

    string funcName	= F.getName().str();
    std::cout<<"Function Name: "<<funcName<<endl;
    
    // skip Orio input function
	if (funcName == "malloc_arrays") return PreservedAnalyses::all();
	if (funcName == "init_input_vars") return PreservedAnalyses::all();

    /*for(ScopInfo::iterator i=si.begin(),e=si.end(),i!=e,++i){
        Something *scop = *i
    }*/

    //llvm::outs()<<"--------------- Woah: "<<si.getNamestr()<<"\n";
    //Use Meliora Loops to find out the scop the candidate loop is in
    
    llvm::outs()<<"------------------------ BEGIN LLVM/OuterLoops------------------------------------- "<<"\n";
    /*
    for(LoopInfo::iterator lt=li.begin(); lt!=li.end(); ++lt){
        Loop* loop = *lt;

        
        //stack<Loop*> stk;
        //stk.push(loop)

        //while(!stk.empty()){
           // Loop *l = stk.top();
            //stk.pop();


        //}


        llvm::outs()<<"Name of the loop: "<<loop->getName()<<"\n";
        auto locrange = loop->getLocRange();
        DebugLoc sline = locrange.getStart();
        DebugLoc eline = locrange.getEnd();

        llvm::outs()<<"Start line: "<<sline.getLine()<<"\n";
        llvm::outs()<<"End line: "<<eline.getLine()<<"\n";
        string loop_cidv = loop->getCanonicalInductionVariable()->getName().str();
        string loop_idv = loop->getInductionVariable(se)->getName().str();
        llvm::outs()<<"Loop Canonical Induction Variable: "<<loop_cidv<<"\n";
        llvm::outs()<<"Loop Induction Variable: "<<loop_idv<<"\n";
        string loop_name = getIdv(loop);
        llvm::outs()<<"Loop Name: "<<loop_name<<"\n";
        loop->print(errs());



        


    }*/
    



    llvm::outs()<<"------------------------ END LLVM/OuterLoops------------------------------------- "<<"\n";

    llvm::outs()<<"------------------------ BEGIN New MemoryAccessPattern Attempt------------------------------------- "<<"\n";

    for(auto &it: si){
        llvm::Region *r = it.first;
        r->print(errs());

        polly::Scop *scp = it.second.get();

        //Check is scp.isEmpty()
        if (scp->isEmpty()== true){
            continue;
        }

        //Scop Name 
        llvm::outs()<<"Scop Name: "<<scp->getNameStr()<<"\n";
        
        //StmtSet stset = scp->Stmts;

        //for(StmtSet::iterator it = stset.begin(); it != stset.end(); it++){
            //polly::ScopStmt s0 = *it;
        //}

        /*
        ArrayRef<polly::ScopStmt *> scp_stmts = scp->getStmtListFor(r);

        size_t scp_stmts_size = scp_stmts.size();
        llvm::outs()<<"Scp_stmts_size: "<<scp_stmts_size<<"\n";

        polly::ScopStmt *f = scp_stmts.front();
        auto const &dt = scp_stmts.data();

        for(ArrayRef<ScopStmt *>::iterator st = scp_stmts.begin(); st != scp_stmts.end(); ++st){
            
            //polly::ScopStmt *s0 = st->data();
            polly::ScopStmt *s = *st;
            std::string domainStr = s->getDomainStr();

            llvm::outs()<<domainStr<<"\n";
            llvm::outs()<<"inside ArrayRef ScopStmt iterator"<<'\n';

        }

        for(auto &sz : scp_stmts){

            polly::ScopStmt *szz = sz;
            llvm::outs()<<szz->getDomainStr()<<"\n";
            llvm::outs()<<"inside ArrayRef ScopStmt iterator"<<'\n';

            int a = 45;
        }*/
        

        //using StmtSet = std::list<ScopStmt>;
        // The statements in this Scop.
            //StmtSet Stmts;
        //std::list<ScopStmt> Stmts //Stmts is a list of polly::ScopStmt(s)    
        for(Scop::iterator scp_it=scp->begin(); scp_it!=scp->end(); ++scp_it){

            polly::ScopStmt &stmt = *scp_it;
            llvm::outs()<<"stmt domain str: "<<stmt.getDomainStr()<<"\n";
            isl::set domain = stmt.getDomain();

            llvm::outs()<<"stmt schedule str: "<<stmt.getScheduleStr()<<"\n";
            isl::map schedule = stmt.getSchedule();

            //Get iteration space of domain

            //isl_ItSpace::vector_tuple2d pointlist = isl_ItSpace::getIterationSpace(domain);
            //isl_ItSpace::print_IterationSpace(pointlist);

            llvm::outs()<<"Getting the iteration space"<<"\n";
            isl_ItSpace::vecvec pointlist = isl_ItSpace::getSetPoints(domain);
            isl_ItSpace::print_vecvec(pointlist);

            llvm::outs()<<"Getting the schedule pattern"<<"\n";
            isl_ItSpace::vecvec schedPointlist = isl_ItSpace::getSchedulePattern(domain,schedule);
            isl_ItSpace::print_vecvec(schedPointlist);

            //Remove this once issues with isl are fixed
            //break;


        }

        //Printing scop stats
        llvm::outs()<<"Scop ID: "<<scp->getID()<<"\n";
        llvm::outs()<<"Scop Name: "<<scp->getNameStr()<<"\n";
        llvm::outs()<<"Scop Function Name: "<<r->getEntry()->getParent()->getName()<<"\n";
    }

    llvm::outs()<<"------------------------ END New MemoryAccessPattern Attempt------------------------------------- "<<"\n";



    llvm::outs()<<"------------------------ BEGIN Polly/Meliora1------------------------------------- "<<"\n";
    vector<Loop*> loopVec;
    getTargetLoops(li, loopVec);
    std::cout<<"Size of vector with Target Loops: "<<loopVec.size()<<endl;

    for(LoopInfo::iterator lp = loopVec.begin(); lp != loopVec.end(); ++lp){
        Loop *loop = *lp;
        string name = getIdv(loop);
        //if (name.substr(0, 5) == "loop_"){
        llvm::outs()<<"----Meliora Loop name: "<<name<<"\n";
        for(auto &It: si){
            llvm::Region *R=It.first;
            R->print(errs());
            polly::Scop *ps = It.second.get();

            llvm::outs()<<"Scop ID: "<<ps->getID()<<"\n";
            llvm::outs()<<"Scop Name: "<<ps->getNameStr()<<"\n";
            //Function pollyF = ps->getFunction();
            llvm::outs()<<"Scop Function Name: "<<R->getEntry()->getParent()->getName()<<"\n";

            bool res = ps->contains(loop);
            llvm::outs()<<"Result of if loop in scop: "<<res<<"\n";


        }
        
    }

    llvm::outs()<<"------------------------ END Polly/Meliora1------------------------------------- "<<"\n";
    

    llvm::outs()<<"------------------------ BEGIN Polly/Meliora2------------------------------------- "<<"\n";
    
    // Program -> Functions -> Scops -> Scops has BBs/loops
    //For scop in ScopInfo

    //Meliora-Polly test code
    
    for(auto &It: si){
        //It: std::pair<llvm::Region*, std::unique_ptr<polly::Scop> >
        llvm::Region *R=It.first;
        R->print(errs());
        polly::Scop *ps = It.second.get();
        //llvm::outs()<<ps;
        llvm::outs()<<"Scop ID: "<<ps->getID()<<"\n";
        llvm::outs()<<"Scop Name: "<<ps->getNameStr()<<"\n";
        //Function pollyF = ps->getFunction();
        llvm::outs()<<"Scop Function Name: "<<R->getEntry()->getParent()->getName()<<"\n";

        bool something=true;
        //ps->print(errs(),something);
        LoopInfo *li_ps = ps->getLI();


        /*
        for (LoopInfo::iterator lp = li_ps->begin(); lp != li_ps->end(); ++lp){
            Loop *l = *lp;

            //Fetching the loop induction varaible
            string name = getIdv(l);
            //if (name.substr(0, 5) == "loop_"){
                llvm::outs()<<"----Loop name: "<<name<<"\n";
            //}
            
        }
        */

       //Checking if Meliora Loop iterator's loop is in the ScOP
       vector<Loop*> loopVec;
       getTargetLoops(li_ps, loopVec);
       std::cout<<"loopVec Polly Size: "<<loopVec.size()<<endl;
       for(LoopInfo::iterator lp = loopVec.begin(); lp != loopVec.end(); ++lp){
           Loop *loop = *lp;
           string name = getIdv(loop);

           //Check if loop is in Scop: ps
           bool loopInScop = ps->contains(loop);
           llvm::outs()<<"Target loop is in Scop: "<<loopInScop<<"\n";
            //if (name.substr(0, 5) == "loop_"){
            llvm::outs()<<"----Filtered Loop name: "<<name<<"\n";
            for(Loop::block_iterator bi= loop->block_begin(); bi!=loop->block_end();++bi){
                BasicBlock* bb = *bi;
                bool bbInScop = ps->contains(bb);
                llvm::outs()<<"Scop contains bb of loop: "<<name<<" ="<<bbInScop<<"\n";
                if(bbInScop){
                    llvm::outs()<<"Found bb in Scop"<<"\n";
                    //extract stmts
                    ArrayRef<ScopStmt *> scop_stmt = ps->getStmtListFor(bb);
                    for(ArrayRef<ScopStmt *>::iterator ss=scop_stmt.begin(); ss!=scop_stmt.end();++ss){
                        polly::ScopStmt *stmt = *ss;
                        llvm::outs()<<"Scop->loop->bb->getDomainStr: "<<stmt->getDomainStr()<<"\n";

                        //Region
                        llvm::outs()<<"Displaying region of identified bb: "<<stmt->getDomainStr()<<"\n";
                        llvm::Region *bbR = stmt->getRegion();
                        R->print(errs());

                        llvm::outs()<<"Printing stmt inside bb: "<<"\n";
                        stmt->print(errs(),something);

                        llvm::outs()<<"Printing insts inside bb: "<<"\n";
                        std::vector<Instruction *> inst_vec = stmt->getInstructions();
                        for(Instruction *I: inst_vec){
                            //llvm::outs()<<I<<"\n";
                            //polly::MemoryAccess* ma = stmt->lookupValueWriteOf(I);
                            const MemoryAccessList* MAL = stmt->lookupArrayAccessesFor(I);

                            if(MAL == nullptr){
                                llvm::outs()<<"Nullptr for: "<<I<<"\n";
                            }
                            else{
                                llvm::outs()<<"NO Nullptr for: "<<I<<"\n";
                            }

                            if(MAL != nullptr){
                                for ( auto mal_it = MAL->begin(); mal_it != MAL->end(); ++mal_it ){
                                    polly::MemoryAccess* ma = *mal_it;

                                    //Access Relation
                                    polly::MemoryAccess::AccessType at = ma->getType();
                                    llvm::outs()<<"Enum: "<<at<<"\n";
                                    isl::map Access_Relation = ma->getLatestAccessRelation();
                                    string Access_Relation_String = ma->getAccessRelationStr();
                                    llvm::outs()<<"Access Relation String: "<<Access_Relation_String<<"\n";
                                }
                                
                            }

                            /*for ( auto mal_it = MAL->begin(); mal_it != MAL->end(); ++mal_it ){
                                //polly::MemoryAccess* ma = *mal_it;
                            }*/

                            /*for(polly::MemoryAccess* mac=MAL->begin();mac!=MAL->end();++mac){

                            }*/

                            //for(polly::MemoryAccess* am: *MAL){

                            //}

                            //llvm::outs()<<"Memory access: "<<ma->getAccessRelationStr()<<"\n";
                            //ma->print(errs());
                        }



                        /*for(BasicBlock::iterator bi=bb->begin(); bi!=bb->end();++bi){
                            Instruction *ins = *bi;

                            polly::MemoryAccess* ma = stmt->lookupValueWriteOf(*ins);
                        }*/
                    }
                }
                else{
                    llvm::outs()<<"Scop does NOT contains bb of loop: "<<name<<" ="<<bbInScop<<"\n";
                }

                
            }

       }
       



        std::cout<<"----Testing polly::Scop Class-----"<<endl;
        llvm::outs()<<"Getting Scop name: "<<ps->getName()<<"\n";
        llvm::outs()<<"Num. of Params: "<<ps->getNumParams()<<"\n";
        llvm::outs()<<"Is Empty? : "<<ps->isEmpty()<<"\n";
        
        llvm::outs()<<"The maximum depth of the loop: "<<ps->getMaxLoopDepth()<<"\n";
        llvm::outs()<<"The number of statements: "<<ps->getSize()<<"\n";
        std::cout<<"----End Testing polly::Scop Class-----"<<endl;
            
        
        //Scop *scp = It.second;
    }
    llvm::outs()<<"------------------------ END Polly/Meliora2------------------------------------- "<<"\n";

    //Testing scop iterator
    /*
    for (auto &It : reverse(si)) {
    if (It.second){
        std::cout<<"Something in here"<<endl;
        cout << "Type of x : " << typeid(It.second).name() << endl;
        //It.second->print(Stream, PollyPrintInstructions);
    }
    else
        std::cout<<"No access"<<endl;
    }
    */
    
    llvm::outs()<<"------------------------ Begin LLVM/loopCounter------------------------------------- "<<"\n";
    
    //Testing LoopInfo
    int loopCounter=0;

    for(LoopInfo::iterator i=li.begin(),e=li.end();i!=e;++i){
        Loop *L = *i;
        int bbCounter=0;
        loopCounter++;

        for(Loop::block_iterator bb=L->block_begin();bb!=L->block_end();++bb){
            bbCounter+=1;
        }
        std::cout<<"Loop ";
        std::cout<<loopCounter;
        std::cout<<": #BBs= ";
        std::cout<<bbCounter;
        std::cout<<"\n";

    }
    llvm::outs()<<"------------------------ END LLVM/loopCounter------------------------------------- "<<"\n";

    llvm::outs()<<"------------------------ BEGIN Meliora/Boost------------------------------------- "<<"\n";

    /*
    //Turn off Meliiora/Util
    //Call util
    hcfg_obj = writeToFile(F, li, layout, BPI, binConfig, se, hcfg_obj, 0);

    //Test hcfg_obj
    std::cout<<"__________________INSIDE CFGGEN___________________"<<endl;
    std::cout<<"__________________HCFG from new container___________________"<<endl;
    std::cout<<"HCFG BaseOutName: "<<hcfg_obj.file_name<<endl;
    std::cout<<"HCFG body: "<<hcfg_obj.file_name<<endl;
    std::cout<<"HCFG kernel_name: "<<hcfg_obj.kernel_name<<endl;
    std::cout<<"HCFG kernel_version: "<<hcfg_obj.kernel_version<<endl;
    std::cout<<"HCFG kernel_variation: "<<hcfg_obj.kernel_variation<<endl;
    std::cout<<"HCFG Loop ID: "<<hcfg_obj.loop_id<<endl;
    std::cout<<"HCFG Loop CNTRL: "<<hcfg_obj.loop_cntrl<<endl;
    std::cout<<"HCFG graph_label: "<<hcfg_obj.graph_label<<endl;
    std::cout<<"HCFG file_name: "<<hcfg_obj.file_name<<endl;
    std::cout<<"HCFG.body: "<<hcfg_obj.body<<endl;

    //Boost Python interpreter
    try{
        //Boost Python Section Below
        // Must be called before any boost::python functions
        Py_Initialize();
        std::cout<<"Inside py init"<<endl;
        //Handling import issues
        //boost::filesystem::path workingDir = boost::filesystem::absolute("./").normalize();
        //PyObject* sysPath = PySys_GetObject("path");
        //PyList_Insert( sysPath, 0, PyLong_FromString(workingDir.string().c_str()));

        ////std::cout <<"Source of opt-9 call" <<current_path()<<endl;

        // import the main module
        object main_module = import("__main__");
        object main_namespace = main_module.attr("__dict__");

        main_namespace["Hcfg"]=class_<Hcfg>("Hcfg",init<>())
                        .def_readonly("body",&Hcfg::body)
                        .def_readonly("kernel_name",&Hcfg::kernel_name)
                        .def_readonly("kernel_version",&Hcfg::kernel_version)
                        .def_readonly("kernel_variation",&Hcfg::kernel_variation)
                        .def_readonly("loop_id",&Hcfg::loop_id)
                        .def_readonly("loop_cntrl",&Hcfg::loop_cntrl)
                        .def_readonly("graph_label",&Hcfg::graph_label)
                        .def_readonly("file_name",&Hcfg::file_name);
        

        main_namespace["hcfg"]=ptr(&hcfg_obj);
        object result = exec_file("/home/users/shravank/projects/meliora2/Meliora/scripts/data_graph_nx_generator.py",main_namespace);
    }
    catch( boost::python::error_already_set const & ) 
    {
        PyErr_Print();
    }

    //Turn off meliora/util.h

    */
		
	llvm::outs()<<"------------------------ END Meliora/Boost------------------------------------- "<<"\n";		

    /*
    //Some standardized example
    for (BasicBlock &BB : F){
        //++NumOfBB;

        for (Instruction &I : BB){
            //(void) I;
            //++NumOfInst;
        }
    } */

    delete layout;
    return PreservedAnalyses::all();
}

//Fold all of the below using Lambda Pass for reducing code clutter
//PassBuilder Callbacks (CB) - To make pass accessible via -passes flag to llvm-opt

bool PipelineParsingCB(
    StringRef Name, FunctionPassManager &FPM,
    ArrayRef<PassBuilder::PipelineElement>) {
        if (Name == "Meliora") {
            FPM.addPass(MelioraPass());
            return true;
        }
        return false;
    }
    
//Register this function at the PassBuilder, a registration callback

void RegisterCB(PassBuilder &PB){
    PB.registerPipelineParsingCallback(PipelineParsingCB);
}

//Plugin needs to provide llvmGetPassPluginInfo() function

extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
llvmGetPassPluginInfo(){
    return {LLVM_PLUGIN_API_VERSION, "Meliora", "v0.1", RegisterCB};
}