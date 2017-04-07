#include "BitwiseShiftRightExpression.h"

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorBitWiseShiftRight.h"

using namespace AST;

BitwiseShiftRightExpression::BitwiseShiftRightExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseShiftRightExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


BitwiseShiftRightExpression::~BitwiseShiftRightExpression()
{

}

Value BitwiseShiftRightExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second >> rightVal.getValue().second);
        return ret;
}

IR::sh_Memory BitwiseShiftRightExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorBitWiseShiftRight>(currentBasicBlock);
}

void BitwiseShiftRightExpression::printOperator() const
{
    std::cout << ">>";
}
