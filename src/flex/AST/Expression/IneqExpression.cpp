#include "IneqExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorNotEquals.h"


using namespace AST;

IneqExpression::IneqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("IneqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


IneqExpression::~IneqExpression() {
    // TODO Auto-generated destructor stub
}

Value IneqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second != right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory IneqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return fcBuildIR<IR::OperatorNotEquals>(currentBasicBlock);
}

void IneqExpression::printOperator() const
{
    std::cout << "!=";
}
