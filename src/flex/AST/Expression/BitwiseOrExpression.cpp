#include "BitwiseOrExpression.h"

using namespace AST;

BitwiseOrExpression::BitwiseOrExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseOrExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitwiseOrExpression::~BitwiseOrExpression() {
        // TODO Auto-generated destructor stub
}

Value BitwiseOrExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second | rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory BitwiseOrExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void BitwiseOrExpression::printOperator() const
{
    std::cout << "|";
}