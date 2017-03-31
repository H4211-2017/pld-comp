#include "ForStructure.h"

using namespace AST;

ForStructure::ForStructure(std::shared_ptr<ComposedInstruction> cond1,
                           std::shared_ptr<ComposedInstruction> cond2,
                           std::shared_ptr<ComposedInstruction> cond3,
                           std::shared_ptr<AbstractInstruction> instr)
    :AbstractStructure("ForStructure")
{
    condInstr1 = cond1;
    condInstr2 = cond2;
    condInstr3 = cond3;
    intInstruction = instr;
}

Value ForStructure::evaluate() const
{
        return value;
}

void ForStructure::printTree(int tabulationNumber) const
{
        AbstractNode::printTree(tabulationNumber);
        if(condInstr1 != nullptr)
        {
                std::cout << std::endl;
                condInstr1->printTree(tabulationNumber + 1);
        }
        if(condInstr2 != nullptr)
        {
                std::cout << std::endl;
                condInstr2->printTree(tabulationNumber + 1);
        }
        if(condInstr3 != nullptr)
        {
                std::cout << std::endl;
                condInstr3->printTree(tabulationNumber + 1);
        }
        if(intInstruction != nullptr)
        {
                std::cout << std::endl;
                intInstruction->printTree(tabulationNumber + 1);
        }
}

IR::sh_Memory ForStructure::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    //add init statement to the current block
    this->condInstr1->buildIR(currentBasicBlock);

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
    this->condInstr2->buildIR(testBasicBlock);
    //loop block is full of instrucitons...
    this->intInstruction->buildIR(loopBasicBlock);
    //... and finish by executing the increment (don't forget that loopBasicBlock may have been updated durring the previous call)
    this->condInstr3->buildIR(loopBasicBlock);

    //update currentBasicBlock so that the caller use the right basic block
    currentBasicBlock = afterBasicBlock;
	return nullptr;
}
