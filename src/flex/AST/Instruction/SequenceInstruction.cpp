#include "SequenceInstruction.h"

using namespace AST;

SequenceInstruction::SequenceInstruction()
    : AbstractNode("SequenceInstruction")
{
}

void SequenceInstruction::addInstruction(std::shared_ptr<AbstractInstruction> instruction)
{
    instructionsList.push_back(instruction);
    this->value = instruction->getValue();
}

void SequenceInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    for (std::shared_ptr<AbstractInstruction> instruction : instructionsList)
    {
        instruction->printTree(tabulationNumber + 1);
        std::cout << std::endl;
    }
}

// TODO
Value SequenceInstruction::evaluate() const
{
	return instructionsList[instructionsList.size()-1]->evaluate();
}

IR::sh_Memory SequenceInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    for(std::shared_ptr<AbstractInstruction> instruction : instructionsList)
    {
        instruction->buildIR(currentBasicBlock);
    }
	return nullptr;
}



