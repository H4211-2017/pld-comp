#include "BitwiseAndExpression.h"

#include <algorithm>

using namespace AST;

BitwiseAndExpression::BitwiseAndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseAndExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitwiseAndExpression::~BitwiseAndExpression() {
        // TODO Auto-generated destructor stub
}

Value BitwiseAndExpression::evaluate() const
{
        Value leftVal= this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second & rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitwiseAndExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitwiseAndExpression::printOperator() const
{
    std::cout << "&";
}
