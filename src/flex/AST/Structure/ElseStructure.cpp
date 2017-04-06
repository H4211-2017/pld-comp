#include <string>

#include "ElseStructure.h"

using namespace AST;

ElseStructure::ElseStructure()
		: AbstractNode("ElseStructure")
{
	intInstruction = nullptr;
}

ElseStructure::ElseStructure(std::shared_ptr<AbstractInstruction> intInstruction)
		: AbstractNode("ElseStructure"), intInstruction(intInstruction)
{
	
}

Value ElseStructure::evaluate() const
{
	return value;
}

void ElseStructure::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
	if(intInstruction != nullptr)
	{	
		std::cout << std::endl;
		intInstruction->printTree(tabulationNumber + 1);
	}
	else
	{
		std::cout << "EXECUTIVE INSTR : EMPTY";
	}
}

IR::sh_Memory ElseStructure::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	if (intInstruction != nullptr)
	{
		return this->intInstruction->buildIR(currentBasicBlock);
	}
}
