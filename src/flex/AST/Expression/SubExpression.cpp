#include "SubExpression.h"

#include <algorithm>

using namespace AST;

SubExpression::SubExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("SubExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


SubExpression::~SubExpression() {
    // TODO Auto-generated destructor stub
}

Value SubExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second - right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void SubExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void SubExpression::printOperator() const
{
    std::cout << "-";
}
