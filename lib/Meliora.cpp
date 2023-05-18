#include "Meliora.h"
//#include "llvm/ADT/Statistic.h"
#include "llvm/Support/Debug.h"
//For printing to standard out
#include "llvm/Support/raw_ostream.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
//Instruction iterator for polly::ScopStmt
#include "llvm/IR/InstIterator.h"

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
#include "polly/Support/GICHelper.h"

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

    llvm::outs()<<"------------------------ BEGIN Polly/Scops-based------------------------------------- "<<"\n";

    for(auto &It: si){

        //LLVM Region of Scop
        llvm::Region *R = It.first;
        R->print(errs());

        //Polly Scop
        polly::Scop *ps = It.second.get();

        //Print Scop Description
        llvm::outs()<<"Scop ID: "<<ps->getID()<<"\n";
        llvm::outs()<<"Scop Name: "<<ps->getNameStr()<<"\n";
        llvm::outs()<<"Function scop belongs too: "<<R->getEntry()->getParent()->getName()<<"\n";

        llvm::outs()<<"Getting Scop name: "<<ps->getName()<<"\n";
        llvm::outs()<<"Num. of Params: "<<ps->getNumParams()<<"\n";
        llvm::outs()<<"Is Empty? : "<<ps->isEmpty()<<"\n";
        llvm::outs()<<"The maximum depth of the loop: "<<ps->getMaxLoopDepth()<<"\n";
        llvm::outs()<<"The number of statements: "<<ps->getSize()<<"\n";

        //Print the Scop
        ps->print(errs(),true);

        //Get all basic blocks of a scop
        llvm::Region::block_range blk_rng = ps->blocks(); //non-const
        int count_blocks = 0;
        for (const auto &BB : ps->blocks()){
            count_blocks +=1;

            //Get Instruction Mix for the BB
            int inst_mix[4]= {0};
            getInstrMix(BB,inst_mix);
            llvm::outs()<<"Instruction Mix: "<<"\n";
            for(const int &n: inst_mix){
                llvm::outs()<<n<<" ";
            }
            llvm::outs()<<"\n";

            //Get the memory access for the BB
            /// A map from basic blocks to vector of SCoP statements. Currently this
            /// vector comprises only of a single statement.
            /// // DenseMap<BasicBlock *, std::vector<ScopStmt *>> StmtMap;
            ArrayRef<ScopStmt *> scop_stmt = ps->getStmtListFor(BB);
            for(auto &stmt: scop_stmt){
                llvm::outs()<<"Scop->loop->bb->getDomainStr: "<<stmt->getDomainStr()<<"\n";
                isl::set domain = stmt->getDomain();

                //Print Stmt inside bb
                llvm::outs()<<"Printing stmt inside bb: "<<"\n";
                stmt->print(errs(),true);

                //Check if statment consists of access
                if(stmt->isEmpty()){
                    llvm::outs()<<"STMT does not contain access"<<"\n";
                }

                //Loop through instructions inside bb->scop
                std::vector<Instruction *> inst_vec = stmt->getInstructions();
                for(Instruction *inst: inst_vec){

                    //Lookup Array Access for Instruction I
                    const MemoryAccessList* MAL = stmt->lookupArrayAccessesFor(inst);
                    //Checking if nullptr returned for Instruction I
                    if(MAL == nullptr){
                                llvm::outs()<<"Nullptr for: "<<inst<<"\n";
                    }
                    else{
                                llvm::outs()<<"NO Nullptr for: "<<inst<<"\n";
                    }

                    //If ArrayAccessFor(I) not nullptr fetch access relation
                    if(MAL != nullptr){
                        for ( auto mal_it = MAL->begin(); mal_it != MAL->end(); ++mal_it ){

                            //Get Access Relation
                            polly::MemoryAccess* ma = *mal_it;
                            polly::MemoryAccess::AccessType at = ma->getType();

                            //Check description of below function
                            //isl::map 	getAddressFunction () const
                            

                            llvm::outs()<<"Enum: "<<at<<"\n";
                            isl::map Access_Relation = ma->getLatestAccessRelation();
                            string Access_Relation_String = ma->getAccessRelationStr();
                            isl::map Address_Function = ma->getAddressFunction();
                            llvm::outs()<<"Access Relation String: "<<Access_Relation_String<<"\n";
                            llvm::outs()<<"Access Function: "<<stringFromIslObj(Address_Function)<<"\n";
                            
                            llvm::outs()<<"Scop->loop->bb->getDomainStr: "<<stmt->getDomainStr()<<"\n";
                            llvm::outs()<<"AR Statement (not domain): "<<stringFromIslObj(Access_Relation.domain())<<"\n";
                            llvm::outs()<<"---Applying domain to access relation-----"<<"\n";
                            /*__isl_give isl_set *isl_set_apply(
                                __isl_take isl_set *set,
                                __isl_take isl_map *map); */
                            
                            //isl::set something = Access_Relation.domain().apply(Access_Relation);
                            //llvm::outs()<<"---Something----->  "<<stringFromIslObj(something)<<"\n";

                            llvm::outs()<<"---Something----->  "<<stringFromIslObj(Address_Function.isl_set_project_onto_map(domain))<<"\n";



                        }

                    }

                    llvm::outs()<<"--------Checking direct memoryaccess:-------"<<"\n";
                    //MemoryAccess *getArrayAccessOrNULLFor(const Instruction *Inst)
                    polly::MemoryAccess* memacs = stmt->getArrayAccessOrNULLFor(inst);
                    if(memacs !=nullptr){
                        //Get number of subscripts
                        unsigned int numSubs = memacs->getNumSubscripts();
                        llvm::outs()<<"Number of subscripts: "<<numSubs<<"\n";

                        //Fetch isl::map AccessRelation
                        isl::map Access_Relation = memacs->getLatestAccessRelation();

                        /// Return an iterator range containing the subscripts.
                        /// iterator_range<SubscriptsTy::const_iterator> subscripts() const 
                        for(auto &some: memacs->subscripts()){
                            llvm::outs()<<"Some: "<<some<<"\n";
                            
                        }

                    }



                }


            }


        }
        llvm::outs()<<"Number of basic blocks in Scop ID "<<ps->getID()<<" is: "<<count_blocks<<"\n";
    }

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
        object result = exec_file("/home/users/shravank/projects/meliora2/meliorapass/scripts/data_graph_nx_generator.py",main_namespace);
    }
    catch( boost::python::error_already_set const & ) 
    {
        PyErr_Print();
    }

    //Turn off meliora/util.h
		
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