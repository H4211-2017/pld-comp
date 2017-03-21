#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <list>
#include <memory>

#include "../instructions/AbstractInstruction.h"

class BasicBlock
{
public:
    BasicBlock();

    void insertNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock);
    void insertNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock);

    void setNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock);
    void setNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock);

private:
    //std::list<AbstractInstruction> instructionsList;
    std::shared_ptr<BasicBlock> nextBlockTrue;
    std::shared_ptr<BasicBlock> nextBlockFalse;
};

#endif // BASICBLOCK_H
