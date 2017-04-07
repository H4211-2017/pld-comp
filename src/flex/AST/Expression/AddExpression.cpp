#include "AddExpression.h"

#include <algorithm>

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorPlus.h"

using namespace AST;

AddExpression::AddExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("AddExpression", leftMember, rightMember)
{
	this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


AddExpression::~AddExpression() {
	// TODO Auto-generated destructor stub
}

Value AddExpression::evaluate() const
{
	Value leftVal = this->leftMember->evaluate();
	Value rightVal = this->rightMember->evaluate();
	Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second + rightVal.getValue().second);
	return ret;
}

IR::sh_Memory AddExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorPlus>(currentBasicBlock);
}

void AddExpression::printOperator() const
{
    std::cout << "+";
}
