#include "MultExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorMult.h"

using namespace AST;

MultExpression::MultExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("MultExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


MultExpression::~MultExpression() {
    // TODO Auto-generated destructor stub
}

Value MultExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second * right.getValue().second);
    return ret;
}

IR::sh_Memory MultExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorMult>(currentBasicBlock);
}

void MultExpression::printOperator() const
{
    std::cout << "*";
}
