#include "DivExpression.h"

#include <algorithm>

using namespace AST;

DivExpression::DivExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("DivExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


DivExpression::~DivExpression() {
    // TODO Auto-generated destructor stub
}

Value DivExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second / right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void DivExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void DivExpression::printOperator() const
{
    std::cout << "/";
}
