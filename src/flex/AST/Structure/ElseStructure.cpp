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
	if(intInstruction != nullptr)
	{	
		AbstractNode::printTree(tabulationNumber);
		std::cout << std::endl;
		intInstruction->printTree(tabulationNumber + 1);
	}
}

void ElseStructure::buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const
{
	
}
