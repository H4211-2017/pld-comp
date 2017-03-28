#include "ReturnInstruction.h"

using namespace AST;

ReturnInstruction::ReturnInstruction()
    : AbstractNode("ReturnInstruction")
{

}

ReturnInstruction::ReturnInstruction(std::shared_ptr<ComposedInstruction> composedInstruction)
    : AbstractNode("ReturnInstruction"), composedInstruction(composedInstruction)
{

}

void ReturnInstruction::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	if(composedInstruction != nullptr)
	{
		composedInstruction->printTree(tabulationNumber + 1);
	}
	
	std::cout << ";" << std::endl;
}

Value ReturnInstruction::evaluate() const
{
	if(composedInstruction != nullptr)
	{
		composedInstruction->evaluate(); // verify if determinist function
	}
	else
	{
		return Value();
	}
}

// TODO
void ReturnInstruction::buildIR() const
{
		
}
