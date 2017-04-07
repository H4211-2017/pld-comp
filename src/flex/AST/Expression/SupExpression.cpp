#include "SupExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorBigger.h"


using namespace AST;

SupExpression::SupExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("SupExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);
}


SupExpression::~SupExpression()
{

}

Value SupExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second > right.getValue().second);
    return ret;
}

IR::sh_Memory SupExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorBigger>(currentBasicBlock);
}

void SupExpression::printOperator() const
{
    std::cout << ">";
}
