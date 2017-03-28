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

virtual void printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	if(composedInstruction.getCount())
	{
		composedInstruction->printTree(tabulationNumber + 1);
	}
	
	std::cout << ";" << std::endl;
}

virtual Value evaluate() const
{
	if(composedInstruction.getCount())
	{
		composedInstruction->evaluate(); // verify if determinist function
	}
	else
	{
		return Value();
	}
}

// TODO
virtual void buildIR() const
{
		
}
