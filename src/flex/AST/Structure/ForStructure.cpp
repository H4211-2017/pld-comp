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
        else
        {
			std::cout << std::endl;
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "INIT INSTR : EMPTY";
		}
        if(condInstr2 != nullptr)
        {
                std::cout << std::endl;
                condInstr2->printTree(tabulationNumber + 1);
        }
        else
        {
			std::cout << std::endl;
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "LOOP CONDITION : EMPTY";
		}
        if(condInstr3 != nullptr)
        {
                std::cout << std::endl;
                condInstr3->printTree(tabulationNumber + 1);
        }
        else
        {
			std::cout << std::endl;
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "LOOP INSTR : EMPTY";
		}
        if(intInstruction != nullptr)
        {
                std::cout << std::endl;
                intInstruction->printTree(tabulationNumber + 1);
        }
        else
        {
			std::cout << std::endl;
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "EXECUTIVE INSTR : EMPTY";
		}
}

IR::sh_Memory ForStructure::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    //add init statement to the current block
    
    if(condInstr1 != nullptr)
    {
		this->condInstr1->buildIR(currentBasicBlock);
	}

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
    //add a flag on basic block
    testBasicBlock->setBasicBlockFlag(IR::Flag::LoopCondition);
    //loop block always go back to test block
    loopBasicBlock->setNextBlockTrue(testBasicBlock);

    //feed the blocks
    //test block is only the tests instructions
    
    if(condInstr2 != nullptr)
    {
		this->condInstr2->buildIR(testBasicBlock);
	}
	
    //loop block is full of instrucitons...
    this->intInstruction->buildIR(loopBasicBlock);
    //... and finish by executing the increment (don't forget that loopBasicBlock may have been updated durring the previous call)
    
    if(condInstr3 != nullptr)
    {
		this->condInstr3->buildIR(loopBasicBlock);
	}
    //add a flag on the loopBasicBlock
    loopBasicBlock->setBasicBlockFlag(IR::Flag::LoopEnd);

    //update currentBasicBlock so that the caller use the right basic block
    currentBasicBlock = afterBasicBlock;
	return nullptr;
}
