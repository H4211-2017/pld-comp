#include <string>

#include "ElseStructure.h"

using namespace AST;

ElseStructure::ElseStructure()
		: AbstractNode("ElseStructure")
{
    elseInstructions = nullptr;
}

ElseStructure::ElseStructure(std::shared_ptr<AbstractInstruction> intInstruction)
        : AbstractNode("ElseStructure"), elseInstructions(intInstruction)
{
	
}

Value ElseStructure::evaluate() const
{
	return value;
}

void ElseStructure::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    if(elseInstructions != nullptr)
	{	
		std::cout << std::endl;
        elseInstructions->printTree(tabulationNumber + 1);
	}
	else
	{
		std::cout << "EXECUTIVE INSTR : EMPTY";
	}
}

IR::sh_Memory ElseStructure::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    if (elseInstructions != nullptr)
	{
        return this->elseInstructions->buildIR(currentBasicBlock);
	}
}
