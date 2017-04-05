#include "ReturnInstruction.h"

#include "../../../IR/generator/Generator.h"

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

IR::sh_Memory ReturnInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{	
	IR::Generator gen;
	IR::sh_Memory returnValueMem = nullptr;
	
	if(composedInstruction != nullptr)
	{
		 returnValueMem = composedInstruction->buildIR(currentBasicBlock);
	}
	
	std::list<IR::sh_AbsInstruction> retInstruction = gen.returnInstruction(returnValueMem);
	currentBasicBlock->pushInstructionBack(retInstruction);
	
	return returnValueMem;
}
