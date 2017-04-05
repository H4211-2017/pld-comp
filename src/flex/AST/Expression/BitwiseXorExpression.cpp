#include "BitwiseXorExpression.h"

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorBitWiseXOr.h"

using namespace AST;

BitwiseXorExpression::BitwiseXorExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("BitwiseXorExpression", leftMember, rightMember)
{
        this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


BitwiseXorExpression::~BitwiseXorExpression() {
        // TODO Auto-generated destructor stub
}

Value BitwiseXorExpression::evaluate() const
{
        Value leftVal = this->leftMember->evaluate();
        Value rightVal = this->rightMember->evaluate();
        Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second ^ rightVal.getValue().second);
        return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory BitwiseXorExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorBitWiseXOr>(currentBasicBlock);
}

void BitwiseXorExpression::printOperator() const
{
    std::cout << "^";
}
