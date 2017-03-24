#include "ComposedInstruction.h"

using namespace AST;

// TODO : verify if it is push_back or push_front
ComposedInstruction::ComposedInstruction(std::shared_ptr<ComposedInstruction> composedInstruction, std::shared_ptr<AbstractExpression> abstractExpression)
    : AbstractNode("ComposedInstruction"), listExpressions(composedInstruction->listExpressions)
{
    listExpressions.push_back(abstractExpression);
}

ComposedInstruction::ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression)
    : AbstractNode("ComposedInstruction")
{
    listExpressions.push_back(abstractExpression);
}

void ComposedInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

    for (std::shared_ptr<AbstractExpression> expression : listExpressions)
    {
        expression->printTree(tabulationNumber + 1);
    }
}
