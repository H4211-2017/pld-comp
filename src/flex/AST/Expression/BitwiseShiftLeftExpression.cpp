#include "BitwiseShiftLeftExpression.h"

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorBitWiseShiftLeft.h"

using namespace AST;

BitwiseShiftLeftExpression::BitwiseShiftLeftExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseShiftLeftExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitwiseShiftLeftExpression::~BitwiseShiftLeftExpression() {
        // TODO Auto-generated destructor stub
}

Value BitwiseShiftLeftExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second << rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory BitwiseShiftLeftExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorBitWiseShiftLeft>(currentBasicBlock);
}

void BitwiseShiftLeftExpression::printOperator() const
{
    std::cout << "<<";
}
