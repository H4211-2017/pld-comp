#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <list>
#include <memory>

#include "../instructions/AbstractInstruction.h"

namespace IR {

    class BasicBlock
    {
    public:
        BasicBlock();

        void pushInstructionBack(std::shared_ptr<AbstractInstruction> instruction);
        void setEndConditionnalInstruction(std::shared_ptr<AbstractInstruction> conditionalInstruction);

        void insertNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock);
        void insertNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock);

        void setNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock);
        void setNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock);

    private:
        std::list<std::shared_ptr<AbstractInstruction>> instructionsList;
        std::shared_ptr<AbstractInstruction> endConditionnalInstruction;
        std::shared_ptr<BasicBlock> nextBlockTrue;
        std::shared_ptr<BasicBlock> nextBlockFalse;
    };
}



#endif // BASICBLOCK_H
