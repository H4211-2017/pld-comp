#include "PlusExpression.h"

using namespace AST;

PlusExpression::PlusExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("PlusExpression", leftMember, rightMember)
{
        this->setType(rightMember->getValue().getValue().first);

}


PlusExpression::~PlusExpression() {
        // TODO Auto-generated destructor stub
}

Value PlusExpression::evaluate() const
{
        Value rightVal = this->rightMember->evaluate();
        Value ret(rightVal.getValue().first, + rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
void PlusExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void PlusExpression::printOperator() const
{
    std::cout << "+";
}
