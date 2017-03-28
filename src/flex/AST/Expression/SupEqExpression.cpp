#include "SupEqExpression.h"

#include <algorithm>


using namespace AST;

SupEqExpression::SupEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("SupEqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


SupEqExpression::~SupEqExpression() {
    // TODO Auto-generated destructor stub
}

Value SupEqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second >= right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void SupEqExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void SupEqExpression::printOperator() const
{
    std::cout << ">=";
}
