#include "SequenceInstruction.h"

using namespace AST;

SequenceInstruction::SequenceInstruction(std::shared_ptr<AbstractInstruction> instruction)
    : AbstractNode("SequenceInstruction")
{
    instructionsList.push_back(instruction);
}

SequenceInstruction::SequenceInstruction(std::shared_ptr<SequenceInstruction> sequenceInstruction, std::shared_ptr<AbstractInstruction> instruction)
    : AbstractNode("SequenceInstruction"), instructionsList(sequenceInstruction->instructionsList)
{
    instructionsList.push_back(instruction);
}
