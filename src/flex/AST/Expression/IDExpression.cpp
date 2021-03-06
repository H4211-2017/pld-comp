#include "IDExpression.h"

#include <algorithm>

using namespace AST;

IDExpression::IDExpression(std::string id, std::shared_ptr<Scope> scope)
    : IDExpression("IDExpression", id, scope)
{

}

IDExpression::IDExpression(std::string name, std::string id, 
		std::shared_ptr<Scope> scope)
    : AbstractExpression(name)
{
	val = scope->findVariable(id);
	
	this->setType(val->getValue().getValue().first);
	
	if(val->isDeclaration())
	{
		std::cerr << "ERROR : Variable is declared but not defined. " << std::endl;
		exit(-1);
	}
}


IDExpression::IDExpression(std::shared_ptr<AbstractVariable> variable, std::shared_ptr<Scope> scope)
    : IDExpression("IDExpression", variable, scope)
{
	
}

IDExpression::IDExpression(std::string name, std::shared_ptr<AbstractVariable> variable, std::shared_ptr<Scope> scope)
    : AbstractExpression(name)
{
	val = variable;
	
	this->setType(val->getValue().getValue().first);
	
	if(val->isDeclaration())
	{
		std::cerr << "ERROR : Variable is declared but not defined. " << std::endl;
		exit(-1);
	}
}

IDExpression::~IDExpression()
{

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

IR::sh_Memory IDExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return val->buildIR(currentBasicBlock);
}
