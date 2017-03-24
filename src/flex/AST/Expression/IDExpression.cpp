#include "IDExpression.h"

#include <algorithm>

using namespace AST;

IDExpression::IDExpression(std::string id,  std::shared_ptr<VariableScope> scope)
    : AbstractExpression("IDExpression")
{
	val = scope->findVariable(id);
}


IDExpression::~IDExpression() {
	// TODO Auto-generated destructor stub
}

Value IDExpression::evaluate() const
{
	return val->evaluate();
}

void IDExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    val->printTree(tabulationNumber + 1);
}

// TODO : create class CFG and replace comment below.
void IDExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{
	
}
