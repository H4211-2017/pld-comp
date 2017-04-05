#include "InfExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorSmaller.h"


using namespace AST;

InfExpression::InfExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("InfExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


InfExpression::~InfExpression() {
    // TODO Auto-generated destructor stub
}

Value InfExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second < right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory InfExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorSmaller>(currentBasicBlock);
}

void InfExpression::printOperator() const
{
    std::cout << "<";
}
