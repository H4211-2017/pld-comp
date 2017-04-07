#include "ModuloExpression.h"

#include <algorithm>

#include "../../../IR/instructions/OperatorModulus.h"

using namespace AST;

ModuloExpression::ModuloExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("ModuloExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


ModuloExpression::~ModuloExpression()
{
	
}

Value ModuloExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second % right.getValue().second);
    return ret;
}

IR::sh_Memory ModuloExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorModulus>(currentBasicBlock);
}

void ModuloExpression::printOperator() const
{
    std::cout << "%";
}
