#include "Block.h"

using namespace AST;

Block::Block()
    : AbstractNode("Block")
{
}

Block::Block(std::shared_ptr<VariableScope> variableScope, std::shared_ptr<SequenceInstruction> sequenceInstr)
    :AbstractNode("Block", variableScope), sequenceInstruction(sequenceInstr)
{

}

void Block::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;

    sequenceInstruction->printTree(tabulationNumber + 1);
}

Value Block::evaluate() const
{
    // TODO
}

void Block::buildIR() const
{
    // TODO
}
