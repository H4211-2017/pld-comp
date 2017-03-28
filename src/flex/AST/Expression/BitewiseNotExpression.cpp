#include "BitewiseNotExpression.h"

using namespace AST;

BitewiseNotExpression::BitewiseNotExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitewiseNotExpression", leftMember, rightMember)
{
        this->setType(rightMember->getValue().getValue().first);

}


BitewiseNotExpression::~BitewiseNotExpression() {
        // TODO Auto-generated destructor stub
}

Value BitewiseNotExpression::evaluate() const
{
        Value rightVal = this->rightMember->evaluate();
        Value ret(rightVal.getValue().first, ~ rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitewiseNotExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitewiseNotExpression::printOperator() const
{
    std::cout << "~";
}
