#include "SupEqExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorBiggerOrEqual.h"


using namespace AST;

SupEqExpression::SupEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("SupEqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


SupEqExpression::~SupEqExpression() {
    // TODO Auto-generated destructor stub
}

Value SupEqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second >= right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory SupEqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorBiggerOrEqual>(currentBasicBlock);
}

void SupEqExpression::printOperator() const
{
    std::cout << ">=";
}
