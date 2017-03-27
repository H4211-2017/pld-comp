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

IfStructure::IfStructure(Value value, std::shared_ptr<ComposedInstruction> condition,
		std::shared_ptr<AbstractInstruction> intInstruction, 
		std::shared_ptr<ElseStructure> elseStructure)
		: AbstractStructure("IfStructure", value), condition(condition),
		intInstruction(intInstruction), elseStructure(elseStructure)
{
	
}

IfStructure::IfStructure(Type type, long int value,
		std::shared_ptr<ComposedInstruction> condition,
		std::shared_ptr<AbstractInstruction> intInstruction, 
		std::shared_ptr<ElseStructure> elseStructure)
		: AbstractStructure("IfStructure", type, value), condition(condition),
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
	
	for (int i = 0; i < tabulationNumber + 1; i++)
    {
        std::cout << "\t";
    }
    
    std::cout << "if" << std::endl;
    condition->printTree(tabulationNumber + 2);
    std::cout << "then" << std::endl;
    intInstruction->printTree(tabulationNumber + 2);
    elseStructure->printTree(tabulationNumber + 2);
}

void IfStructure::buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const
{
	
}
