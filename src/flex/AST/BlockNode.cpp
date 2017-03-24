#include "BlockNode.h"

using namespace AST;

BlockNode::BlockNode()
    : AbstractNode("BlockNode")
{
}

BlockNode::BlockNode(std::shared_ptr<VariableScope> variableScope, std::shared_ptr<SequenceInstruction> sequenceInstr)
    :AbstractNode("BlockNode", variableScope), sequenceInstr(sequenceInstr)
{

}
