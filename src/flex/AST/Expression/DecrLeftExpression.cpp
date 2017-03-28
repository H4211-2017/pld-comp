#include "DecrLeftExpression.h"

#include <algorithm>

using namespace AST;

DecrLeftExpression::DecrLeftExpression(std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("DecrLeftExpression", rightMember)
{
    this->setType(rightMember->getValue().getValue().first);

}


DecrLeftExpression::~DecrLeftExpression() {
    // TODO Auto-generated destructor stub
}

Value DecrLeftExpression::evaluate() const
{
    Value right = this->rightMember->evaluate();
    Value ret();
    return ret;
}

// TODO : create class CFG and replace comment below.
void DecrLeftExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void DecrLeftExpression::printOperator() const
{
    std::cout << "++";
}
