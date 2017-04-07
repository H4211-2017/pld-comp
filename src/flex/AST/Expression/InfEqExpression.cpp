#include "InfEqExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorSmallerOrEqual.h"

using namespace AST;

InfEqExpression::InfEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("InfEqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);
}


InfEqExpression::~InfEqExpression()
{

}

Value InfEqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second <= right.getValue().second);
    return ret;
}

IR::sh_Memory InfEqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorSmallerOrEqual>(currentBasicBlock);
}

void InfEqExpression::printOperator() const
{
    std::cout << "<=";
}
