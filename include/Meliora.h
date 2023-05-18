#ifndef MELIORA_H
#define MELIORA_H

#include "llvm/IR/PassManager.h"

class MelioraPass : public llvm::PassInfoMixin<MelioraPass>{
    public:
        llvm::PreservedAnalyses run(llvm::Function &F, llvm::FunctionAnalysisManager &AM);

};

#endif