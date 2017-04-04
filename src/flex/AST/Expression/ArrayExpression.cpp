#include "ArrayExpression.h"

#include <algorithm>

using namespace AST;

ArrayExpression::ArrayExpression(std::string id, std::shared_ptr<AbstractExpression> caseExpression, 
	std::shared_ptr<Scope> scope)
    : IDExpression("ArrayExpression", id, scope), caseExpression(caseExpression)
{
	
}

ArrayExpression::~ArrayExpression()
{
	// TODO Auto-generated destructor stub
}

Value ArrayExpression::evaluate() const
{
	return val->evaluate();
}

void ArrayExpression::printTree(int tabulationNumber) const
{
    IDExpression::printTree(tabulationNumber);
    std::cout << "case :" << std::endl;
    caseExpression->printTree(tabulationNumber + 1);
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory ArrayExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}
