#include "AbstractVariable.h"

#include <sstream>
#include <iostream>

using namespace AST;

AbstractVariable::AbstractVariable(std::string name, std::shared_ptr<VariableSignature> signature, bool decl)
	: AbstractNode(name), declaration(decl)
{
	sig = signature;
	this->setType(sig->getValue().getValue().first);
}

bool AbstractVariable::isDeclaration() const
{
	return declaration;
}

void AbstractVariable::noLongerDeclaration()
{
	declaration = false;
}
        
void AbstractVariable::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
    std::cout << "| Name variable : " << sig->getIdentifiant() << std::endl;
	sig->printTree(tabulationNumber + 1);
}

const std::shared_ptr<const VariableSignature> AbstractVariable::getVariableSignature() const
{
	return sig;
}
