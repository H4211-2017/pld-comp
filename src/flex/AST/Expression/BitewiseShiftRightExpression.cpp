#include "BitewiseShiftRightExpression.h"


using namespace AST;

BitewiseShiftRightExpression::BitewiseShiftRightExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitewiseShiftRightExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitewiseShiftRightExpression::~BitewiseShiftRightExpression() {
        // TODO Auto-generated destructor stub
}

Value BitewiseShiftRightExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second >> rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitewiseShiftRightExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitewiseShiftRightExpression::printOperator() const
{
    std::cout << ">>";
}

