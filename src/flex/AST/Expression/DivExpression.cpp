#include "DivExpression.h"

#include <algorithm>

using namespace AST;

DivExpression::DivExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("DivExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


DivExpression::~DivExpression()
{

}

Value DivExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second / right.getValue().second);
    return ret;
}

IR::sh_Memory DivExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void DivExpression::printOperator() const
{
    std::cout << "/";
}
