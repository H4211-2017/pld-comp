#include "SubExpression.h"

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorMinus.h"

#include <algorithm>

using namespace AST;

SubExpression::SubExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("SubExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


SubExpression::~SubExpression() {
    // TODO Auto-generated destructor stub
}

Value SubExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second - right.getValue().second);
    return ret;
}

IR::sh_Memory SubExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void SubExpression::printOperator() const
{
    std::cout << "-";
}
