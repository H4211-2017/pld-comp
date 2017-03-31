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
		if(instruction != nullptr)
			instruction->printTree(tabulationNumber + 1);
		else
		{
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "EMPTY";
		}
        std::cout << std::endl;
    }
}

// TODO
Value SequenceInstruction::evaluate() const
{
	return Value();
}

// TODO
void SequenceInstruction::buildIR() const
{

}



