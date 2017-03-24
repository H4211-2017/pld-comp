#include "SequenceInstruction.h"

using namespace AST;

SequenceInstruction::SequenceInstruction(std::shared_ptr<AbstractInstruction> instruction)
    : AbstractNode("SequenceInstruction")
{
    instructionsList.push_back(instruction);
}

void SequenceInstruction::addInstruction(std::shared_ptr<AbstractInstruction> instruction)
{
    instructionsList.push_back(instruction);
}

void SequenceInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    for (std::shared_ptr<AbstractInstruction> instruction : instructionsList)
    {
        instruction->printTree(tabulationNumber + 1);
    }
}

// TODO
Value SequenceInstruction::evaluate() const
{

}

// TODO
void SequenceInstruction::buildIR() const
{

}



