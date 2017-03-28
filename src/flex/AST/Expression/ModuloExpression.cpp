#include "ModuloExpression.h"

#include "ModuloExpression.h"

#include <algorithm>

using namespace AST;



ModuloExpression::ModuloExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("ModuloExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


ModuloExpression::~ModuloExpression() {
    // TODO Auto-generated destructor stub
}

Value ModuloExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second % right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
void ModuloExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{

}

void ModuloExpression::printOperator() const
{
    std::cout << "%";
}
