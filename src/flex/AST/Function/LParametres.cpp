#include "LParametres.h"

#include "Scope.h"
#include "Variable/Variable.h"

#include <iostream>

using namespace AST;

LParametres::LParametres()
	: AbstractNode("LParametres")
{

}
LParametres::LParametres(std::shared_ptr<AbstractExpression> parametre)
	: LParametres()
{
	this->addParametre(parametre);
}
		
void LParametres::addParametre(std::shared_ptr<AbstractExpression> parametre)
{
    parameters.push_back(parametre);
	
}
		
Value LParametres::evaluate() const
{
	return Value();
}

void LParametres::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << std::endl;
    for(int i = 0; i < parameters.size(); i++)
	{
        parameters[i]->printTree(tabulationNumber + 1);
		std::cout << std::endl;
	}
}

std::vector<std::shared_ptr<AbstractExpression> > LParametres::getParameters()
{
    return parameters;
}

IR::sh_Memory LParametres::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}
