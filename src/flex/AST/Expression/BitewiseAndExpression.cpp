#include "BitewiseAndExpression.h"

#include <algorithm>

using namespace AST;

BitewiseAndExpression::BitewiseAndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitewiseAndExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitewiseAndExpression::~BitewiseAndExpression() {
        // TODO Auto-generated destructor stub
}

Value BitewiseAndExpression::evaluate() const
{
        Value left = this->leftMember->evaluate();
        Value right = this->rightMember->evaluate();
        Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second + right.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitewiseAndExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitewiseAndExpression::printOperator() const
{
    std::cout << "&";
}
