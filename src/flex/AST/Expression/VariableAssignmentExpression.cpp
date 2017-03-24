#include "VariableAssignmentExpression.h"

using namespace AST;

VariableAssignmentExpression::VariableAssignmentExpression(std::shared_ptr<Variable> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("VariableAssignmentExpression", leftMember, rightMember)
{
    //TODO : check if left member is a declared variable
}

Value VariableAssignmentExpression::evaluate() const
{
    return rightMember->evaluate();
}

void VariableAssignmentExpression::printOperator() const
{
    std::cout << "=";
}
