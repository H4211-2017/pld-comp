#include <string>

#include "ElseStructure.h"

using namespace AST;

ElseStructure::ElseStructure()
		: AbstractNode("ElseStructure")
{
	
}

ElseStructure::ElseStructure(std::shared_ptr<AbstractInstruction> intInstruction)
		: AbstractNode("ElseStructure"), intInstruction(intInstruction)
{
	
}

ElseStructure::ElseStructure(Value value, std::shared_ptr<AbstractInstruction> intInstruction)
		: AbstractNode("ElseStructure", value), intInstruction(intInstruction)
{
	
}

ElseStructure::ElseStructure(Type type, long int value, std::shared_ptr<AbstractInstruction> intInstruction)
		: AbstractNode("ElseStructure", type, value), intInstruction(intInstruction)
{
	
}

Value ElseStructure::evaluate() const
{
	return value;
}

void ElseStructure::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << std::endl;
	
	for (int i = 0; i < tabulationNumber + 1; i++)
    {
        std::cout << "\t";
    }
    
    std::cout << "else" << std::endl;
    intInstruction->printTree(tabulationNumber + 2);
}

void ElseStructure::buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const
{
	
}
