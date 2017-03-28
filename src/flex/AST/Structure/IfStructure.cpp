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

    intInstruction->printTree(tabulationNumber + 1);

	if(elseStructure != nullptr)
	{	
		elseStructure->printTree(tabulationNumber + 1);
	}
}

void IfStructure::buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const
{
	
}
