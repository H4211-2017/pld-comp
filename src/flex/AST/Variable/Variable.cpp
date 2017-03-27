#include "Variable.h"

#include <sstream>
#include <iostream>

using namespace AST;

Variable::Variable(std::shared_ptr<VariableSignature> signature, bool decl)
	: AbstractNode("Variable"), declaration(decl)
{
	sig = signature;
	this->setType(sig->getValue().getValue().first);
}

bool Variable::isDeclaration() const
{
	return declaration;
}

void Variable::noLongerDeclaration()
{
	declaration = false;
}
        
void Variable::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << std::endl;
	sig->printTree(tabulationNumber + 1);
}

Value Variable::evaluate() const
{
	return Value();
}

void Variable::buildIR() const
{

}
