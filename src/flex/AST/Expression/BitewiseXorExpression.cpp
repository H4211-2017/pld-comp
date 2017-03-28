#include "BitewiseXorExpression.h"

using namespace AST;

BitewiseXorExpression::BitewiseXorExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitewiseXorExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitewiseXorExpression::~BitewiseXorExpression() {
        // TODO Auto-generated destructor stub
}

Value BitewiseXorExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second ^ rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void BitewiseXorExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void BitewiseXorExpression::printOperator() const
{
    std::cout << "^";
}
