#include "WhileStructure.h"

using namespace AST;

WhileStructure::WhileStructure(std::shared_ptr<ComposedInstruction> condition,
                               std::shared_ptr<AbstractInstruction> instruction)
    :AbstractStructure("WhileStructure")
{
    this->condition = condition;
    this->intInstruction = instruction;
}

Value WhileStructure::evaluate() const
{
    return value;
}

void WhileStructure::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    if(condition != nullptr)
    {
        std::cout << std::endl;
        condition->printTree(tabulationNumber + 1);
    }
    if(intInstruction != nullptr)
    {
        std::cout << std::endl;
        intInstruction->printTree(tabulationNumber + 1);
    }

}

void WhileStructure::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    IR::sh_BasicBlock loopBasicBlock = std::make_shared<IR::BasicBlock>();
    IR::sh_BasicBlock testBasicBlock = std::make_shared<IR::BasicBlock>();
    IR::sh_BasicBlock afterBasicBlock = std::make_shared<IR::BasicBlock>();

    //link BasicBlocks
    //set next block of after block as the old next bock of current block
    afterBasicBlock->setNextBlockTrue(currentBasicBlock->getNextBlockTrue());
    //current block automaticaly go to test block
    currentBasicBlock->setNextBlockTrue(testBasicBlock);
    //test block go to loop if true and after if false
    testBasicBlock->setNextBlockTrue(loopBasicBlock);
    testBasicBlock->setNextBlockFalse(afterBasicBlock);
    //loop block always go back to test block
    loopBasicBlock->setNextBlockTrue(testBasicBlock);

    //feed the blocks
    //test block is only the tests instructions
    this->condition->buildIR(testBasicBlock);
    //loop block is full of instrucitons...
    this->intInstruction->buildIR(loopBasicBlock);

    //update currentBasicBlock so that the caller use the right basic block
    currentBasicBlock = afterBasicBlock;
}
