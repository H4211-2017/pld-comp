#include "SupEqExpression.h"

#include <algorithm>

using namespace AST;

SupEqExpression::SupEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("SupEqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);
}


SupEqExpression::~SupEqExpression()
{

}

Value SupEqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second >= right.getValue().second);
    return ret;
}

IR::sh_Memory SupEqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void SupEqExpression::printOperator() const
{
    std::cout << ">=";
}
