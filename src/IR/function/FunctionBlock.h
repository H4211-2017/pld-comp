#ifndef FUNCTIONBLOCK_H
#define FUNCTIONBLOCK_H

#include <memory>

#include "AbstractFunction.h"
#include "../basicBlock/BasicBlock.h"

namespace IR {
    class FunctionBlock : public AbstractFunction
    {
    public:
        FunctionBlock(std::string name);

        void generateBasicBlockList();

        sh_BasicBlock getFunctionCore() const;
        void setFunctionCore(const sh_BasicBlock &value);

        std::list<sh_BasicBlock> getCoreList() const;

        void printIR(std::ostream &os) const;

        std::shared_ptr<const BasicBlock> getFunctionReturn() const;

    protected:
        void exploreBasicBlock(sh_BasicBlock currentBlock);
        bool isBasicBlockAlreadyExplored(sh_BasicBlock currentBlock) const;

    private:
        sh_BasicBlock functionInit;
        sh_BasicBlock functionCore;
        sh_BasicBlock functionReturn;

        std::list<sh_BasicBlock> coreList;
    };
}

#endif // FUNCTIONBLOCK_H
