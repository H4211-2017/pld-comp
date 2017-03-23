#include "VariableAssignmentExpression.h"

using namespace AST;

VariableAssignmentExpression::VariableAssignmentExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember)
    : AbstractBinaryExpression(rightMember,leftMember)
{
}

Value VariableAssignmentExpression::evaluate() const
{
    return rightMember->evaluate();
}


void VariableAssignmentExpression::printTree(int tabulationNumber) const {
    AbstractNode::printTree(tabulationNumber);
    leftMember->printTree(tabulationNumber+1);
    std::cout<<'='<<std::endl;
    rightMember->printTree(tabulationNumber+1);
}
