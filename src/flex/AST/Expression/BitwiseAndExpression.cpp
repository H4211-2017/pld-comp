#include "BitwiseAndExpression.h"

#include <algorithm>

using namespace AST;

BitwiseAndExpression::BitwiseAndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseAndExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


BitwiseAndExpression::~BitwiseAndExpression()
{

}

Value BitwiseAndExpression::evaluate() const
{
        Value leftVal= this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second & rightVal.getValue().second);
        return ret;
}

IR::sh_Memory BitwiseAndExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void BitwiseAndExpression::printOperator() const
{
    std::cout << "&";
}
