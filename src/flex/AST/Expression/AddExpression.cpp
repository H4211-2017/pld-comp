#include "AddExpression.h"

#include <algorithm>

using namespace AST;

AddExpression::AddExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember)
    : AbstractBinaryExpression(rightMember, leftMember)
{
	
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

void AddExpression::printTree(int tabulationNumber) const
{
	
}

// TODO : create class CFG and replace comment below.
void AddExpression::buildIR(/*std::shared_ptr<CFG>*/) const
{
	
}
