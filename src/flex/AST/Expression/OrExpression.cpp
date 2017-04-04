#include "OrExpression.h"

#include <algorithm>

using namespace AST;

OrExpression::OrExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("OrExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


OrExpression::~OrExpression() {
    // TODO Auto-generated destructor stub
}

Value OrExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second || right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory OrExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void OrExpression::printOperator() const
{
    std::cout << "||";
}
