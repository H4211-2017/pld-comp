#include "EqExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorEquals.h"

using namespace AST;

EqExpression::EqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("EqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);
}


EqExpression::~EqExpression()
{

}

Value EqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second == right.getValue().second);
    return ret;
}

IR::sh_Memory EqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	BINARY_OPERATOR_IR(OperatorEquals)
}

void EqExpression::printOperator() const
{
    std::cout << "==";
}
