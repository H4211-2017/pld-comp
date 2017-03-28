#include "InfEqExpression.h"

#include <algorithm>


using namespace AST;

InfEqExpression::InfEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("InfEqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


InfEqExpression::~InfEqExpression() {
    // TODO Auto-generated destructor stub
}

Value InfEqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second <= right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void InfEqExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void InfEqExpression::printOperator() const
{
    std::cout << "<=";
}
