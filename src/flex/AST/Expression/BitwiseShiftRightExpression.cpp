#include "BitwiseShiftRightExpression.h"

using namespace AST;

BitwiseShiftRightExpression::BitwiseShiftRightExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseShiftRightExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitwiseShiftRightExpression::~BitwiseShiftRightExpression() {
        // TODO Auto-generated destructor stub
}

Value BitwiseShiftRightExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second >> rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory BitwiseShiftRightExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

void BitwiseShiftRightExpression::printOperator() const
{
    std::cout << ">>";
}
