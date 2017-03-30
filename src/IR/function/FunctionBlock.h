#ifndef FUNCTIONBLOCK_H
#define FUNCTIONBLOCK_H

#include <memory>
#include <queue>

#include "AbstractFunction.h"
#include "../basicBlock/BasicBlock.h"

namespace IR {
    class FunctionBlock : public AbstractFunction
    {
    public:
        FunctionBlock(std::string name);

        void generateBasicBlockList();
        void getMemoryFromBasicBlock();
        void aliveRegistryDetection();
        void affectRegistry(std::queue<std::string> asmRegistryAvailable);

        sh_BasicBlock getFunctionCore() const;
        void setFunctionCore(const sh_BasicBlock &value);

        std::list<sh_BasicBlock> getCoreList() const;

        void printIR(std::ostream &os) const;

        std::shared_ptr<const BasicBlock> getFunctionReturn() const;

    protected:
        void exploreBasicBlock(sh_BasicBlock currentBlock);
        bool isBasicBlockAlreadyExplored(sh_BasicBlock currentBlock) const;
        void exploreBasicBlockToFindAliveRegister(sh_BasicBlock basicBlock, std::map<std::__cxx11::string, sh_Register> aliveRegister);

    private:
        sh_BasicBlock functionInit;
        sh_BasicBlock functionCore;
        sh_BasicBlock functionReturn;

        std::list<sh_BasicBlock> coreList;

        std::map<std::string,sh_AbstractData> usedMemory;
    };
}

#endif // FUNCTIONBLOCK_H
