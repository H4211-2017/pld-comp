#include "Block.h"

using namespace AST;

Block::Block()
    : AbstractNode("Block")
{
}

Block::Block(std::shared_ptr<VariableScope> variableScope, std::shared_ptr<SequenceInstruction> sequenceInstr)
    :AbstractNode("Block", variableScope), sequenceInstr(sequenceInstr)
{

}
