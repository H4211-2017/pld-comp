#include "EqExpression.h"

#include <algorithm>


using namespace AST;

EqExpression::EqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("EqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


EqExpression::~EqExpression() {
    // TODO Auto-generated destructor stub
}

Value EqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second == right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory EqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void EqExpression::printOperator() const
{
    std::cout << "==";
}
