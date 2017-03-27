#include "AddExpression.h"

#include <algorithm>

using namespace AST;

AddExpression::AddExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("AddExpression", leftMember, rightMember)
{
	this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
	
}


AddExpression::~AddExpression() {
	// TODO Auto-generated destructor stub
}

Value AddExpression::evaluate() const
{
	Value left = this->leftMember->evaluate();
	Value right = this->rightMember->evaluate();
	Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second + right.getValue().second);
	return ret;
}

// TODO : create class CFG and replace comment below.
void AddExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{
	
}

void AddExpression::printOperator() const
{
    std::cout << "+";
}
