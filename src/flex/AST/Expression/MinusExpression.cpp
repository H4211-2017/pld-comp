#include "MinusExpression.h"

using namespace AST;

MinusExpression::MinusExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("MinusExpression", leftMember, rightMember)
{
        this->setType(rightMember->getValue().getValue().first);

}


MinusExpression::~MinusExpression() {
        // TODO Auto-generated destructor stub
}

Value MinusExpression::evaluate() const
{
        Value rightVal = this->rightMember->evaluate();
        Value ret(rightVal.getValue().first, - rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void MinusExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void MinusExpression::printOperator() const
{
    std::cout << "-";
}
