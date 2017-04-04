#include "ReturnInstruction.h"

using namespace AST;

ReturnInstruction::ReturnInstruction()
    : AbstractNode("ReturnInstruction")
{

}

ReturnInstruction::ReturnInstruction(std::shared_ptr<ComposedInstruction> composedInstruction)
    : AbstractNode("ReturnInstruction"), composedInstruction(composedInstruction)
{
	this->value = composedInstruction->getValue();
}

void ReturnInstruction::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	if(composedInstruction != nullptr)
	{
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
	IR::sh_Memory retMem = nullptr;
	
	if(composedInstruction != nullptr)
	{
		retMem = composedInstruction->buildIR(currentBasicBlock);
	}
	
	return retMem;
}
