#include "InfExpression.h"

#include <algorithm>


using namespace AST;

InfExpression::InfExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("InfExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


InfExpression::~InfExpression() {
    // TODO Auto-generated destructor stub
}

Value InfExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second < right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void InfExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}

void InfExpression::printOperator() const
{
    std::cout << "<";
}
