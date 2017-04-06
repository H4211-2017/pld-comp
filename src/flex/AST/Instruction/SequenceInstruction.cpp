#include "SequenceInstruction.h"

using namespace AST;

SequenceInstruction::SequenceInstruction()
    : AbstractNode("SequenceInstruction")
{

}

void SequenceInstruction::addInstruction(std::shared_ptr<AbstractInstruction> instruction)
{
    instructionsList.push_back(instruction);
    
    if(instruction != nullptr)
		this->value = instruction->getValue();
}

void SequenceInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    for (int i=0; i<instructionsList.size(); i++)
    {
		if(instructionsList[i] != nullptr)
			instructionsList[i]->printTree(tabulationNumber + 1);
		else
		{
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "EMPTY";
		}
        std::cout << std::endl;
    }
}

Value SequenceInstruction::evaluate() const
{
	return Value();
}

IR::sh_Memory SequenceInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    for(std::shared_ptr<AbstractInstruction> instruction : instructionsList)
    {
		if(instruction != nullptr)
			instruction->buildIR(currentBasicBlock);
    }
	return nullptr;
}



