#include "BitewiseOrExpression.h"

using namespace AST;

BitewiseOrExpression::BitewiseOrExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitewiseOrExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitewiseOrExpression::~BitewiseOrExpression() {
        // TODO Auto-generated destructor stub
}

Value BitewiseOrExpression::evaluate() const
{
        Value left = this->leftMember->evaluate();
        Value right = this->rightMember->evaluate();
        Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second + right.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitewiseOrExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitewiseOrExpression::printOperator() const
{
    std::cout << "|";
}
