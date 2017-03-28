#include "BitewiseShiftLeftExpression.h"

using namespace AST;

BitewiseShiftLeftExpression::BitewiseShiftLeftExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitewiseShiftLeftExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitewiseShiftLeftExpression::~BitewiseShiftLeftExpression() {
        // TODO Auto-generated destructor stub
}

Value BitewiseShiftLeftExpression::evaluate() const
{
        Value left = this->leftMember->evaluate();
        Value right = this->rightMember->evaluate();
        Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second + right.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitewiseShiftLeftExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitewiseShiftLeftExpression::printOperator() const
{
    std::cout << "<<";
}
