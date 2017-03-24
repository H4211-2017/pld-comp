#include "Block.h"

using namespace AST;

Block::Block()
    : AbstractNode("Block")
{
}

Block::Block(std::shared_ptr<VariableScope> variableScope, std::shared_ptr<SequenceInstruction> sequenceInstr)
    :AbstractNode("Block", variableScope), sequenceInstruction(sequenceInstr)
{
	this->value = sequenceInstruction->getValue();
}

void Block::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    if(this->sequenceInstruction != nullptr)
    	sequenceInstruction->printTree(tabulationNumber + 1);
}

Value Block::evaluate() const
{
	if(this->sequenceInstruction != nullptr)
    	return this->sequenceInstruction->evaluate();
    else
    	return Value();
}

std::shared_ptr<VariableScope> Block::getScope() const
{
    return std::make_shared<VariableScope>(currentVariableScope);
}

void Block::buildIR() const
{
    // TODO
}
