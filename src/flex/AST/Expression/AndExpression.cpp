#include "AndExpression.h"

#include <algorithm>


using namespace AST;

AndExpression::AndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("AndExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


AndExpression::~AndExpression() {
    // TODO Auto-generated destructor stub
}

Value AndExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second && right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void AndExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void AndExpression::printOperator() const
{
    std::cout << "&&";
}
