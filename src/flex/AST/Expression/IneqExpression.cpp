#include "IneqExpression.h"

#include <algorithm>


using namespace AST;

IneqExpression::IneqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("IneqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


IneqExpression::~IneqExpression() {
    // TODO Auto-generated destructor stub
}

Value IneqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second != right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void IneqExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void IneqExpression::printOperator() const
{
    std::cout << "!=";
}
