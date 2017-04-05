#include "ReturnInstruction.h"

using namespace AST;

ReturnInstruction::ReturnInstruction()
    : AbstractInstruction("ReturnInstruction")
{

}

ReturnInstruction::ReturnInstruction(std::shared_ptr<ComposedInstruction> composedInstruction)
    : AbstractInstruction("ReturnInstruction"), composedInstruction(composedInstruction)
{
	this->value = composedInstruction->getValue();
}

void ReturnInstruction::printTree(int tabulationNumber) const
{
	AbstractInstruction::printTree(tabulationNumber);
	if(composedInstruction != nullptr)
	{
		std::cout << std::endl;
		for(int i=0; i<=tabulationNumber; i++)
		{
			std::cout << "  ";
		}
		composedInstruction->printTree(tabulationNumber + 1);
	}
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
IR::sh_Memory ReturnInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{	
	if(composedInstruction != nullptr)
	{
		 return composedInstruction->buildIR(currentBasicBlock);
	}
	
	return nullptr;
}
