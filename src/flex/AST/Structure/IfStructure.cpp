#include <string>

#include "IfStructure.h"

using namespace AST;

IfStructure::IfStructure(std::shared_ptr<ComposedInstruction> condition,
		std::shared_ptr<AbstractInstruction> intInstruction, 
		std::shared_ptr<ElseStructure> elseStructure)
		: AbstractStructure("IfStructure"), condition(condition),
		intInstruction(intInstruction), elseStructure(elseStructure)
{
	
}

Value IfStructure::evaluate() const
{
	return value;
}

void IfStructure::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);	
    std::cout << std::endl;
    condition->printTree(tabulationNumber + 1);
    std::cout << std::endl;


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

	if(elseStructure != nullptr)
	{	
		std::cout << std::endl;
		elseStructure->printTree(tabulationNumber + 1);
	}
}

/**
 * @brief IfStructure::buildIR generate the IR structure needed to code a if/else statment
 * @param currentBasicBlock reference to the BasicBlock where the code will be generated.
 * This reference will be updated to the currentBasicBlock needed for next buildIR call.
 */
IR::sh_Memory IfStructure::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    //add condition at what will become the end of the current basic block
    this->condition->buildIR(currentBasicBlock);

    IR::sh_BasicBlock thenBasicBlock = std::make_shared<IR::BasicBlock>();
    IR::sh_BasicBlock afterBasicBlock = std::make_shared<IR::BasicBlock>();

    //set next block of after block as the old next bock of current block
    afterBasicBlock->setNextBlockTrue(currentBasicBlock->getNextBlockTrue());
    //set then block links
    currentBasicBlock->setNextBlockTrue(thenBasicBlock);
    thenBasicBlock->setNextBlockTrue(afterBasicBlock);

    //feed then block
    this->intInstruction->buildIR(thenBasicBlock);

    if(this->elseStructure == nullptr)
    {
        //if else don't exist
        //link current block to after block in case of false
        currentBasicBlock->setNextBlockFalse(afterBasicBlock);
    }
    else
    {
        IR::sh_BasicBlock elseBasicBlock = std::make_shared<IR::BasicBlock>();
        //set else block links
        currentBasicBlock->setNextBlockFalse(elseBasicBlock);
        elseBasicBlock->setNextBlockTrue(afterBasicBlock);
        //feed else block
        this->elseStructure->buildIR(elseBasicBlock);
    }

    //update currentBasicBlock so that the caller use the right basic block
    currentBasicBlock = afterBasicBlock;
	return nullptr;
}
