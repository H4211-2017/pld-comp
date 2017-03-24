#include "ComposedInstruction.h"

using namespace AST;

ComposedInstruction::ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression)
    : AbstractNode("ComposedInstruction")
{
    listExpressions.push_back(abstractExpression);
}

void ComposedInstruction::addExpression(std::shared_ptr<AbstractExpression> expression)
{
    listExpressions.push_back(expression);
}

void ComposedInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

    for (std::shared_ptr<AbstractExpression> expression : listExpressions)
    {
        expression->printTree(tabulationNumber + 1);
    }
}

// TODO
Value ComposedInstruction::evaluate() const
{

}

// TODO
void ComposedInstruction::buildIR() const
{

}
