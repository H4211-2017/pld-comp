#include "MultExpression.h"

#include <algorithm>

using namespace AST;

MultExpression::MultExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("MultExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


MultExpression::~MultExpression()
{

}

Value MultExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second * right.getValue().second);
    return ret;
}

IR::sh_Memory MultExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void MultExpression::printOperator() const
{
    std::cout << "*";
}
