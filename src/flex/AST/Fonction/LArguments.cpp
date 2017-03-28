#include "LArguments.h"

#include <iostream>
#include <sstream>

using namespace AST;

LArguments::LArguments()
	: AbstractNode("LArguments"), isForDecl(false)
{

}
LArguments::LArguments(std::shared_ptr<VariableSignature> argument)
	: LArguments()
{
	this->addArgument(argument);
}
		
void LArguments::addArgument(std::shared_ptr<VariableSignature> argument)
{
	if(argument->getIdentifiant().compare("") == 0)
	{
		isForDecl = true;
		arguments.push_back(argument);
		return;
	}
	for(int i = 0; i < arguments.size(); i++)
	{
		if(arguments[i]->getIdentifiant().compare(argument->getIdentifiant()) == 0)
		{
			std::stringstream ss;
			ss << "ERROR inserting argument number " << arguments.size() << " : argument number " << i << "is alreadey named <"<< arguments[i]->getIdentifiant() << ">";
			throw ss.str();
		}
	}
	
	arguments.push_back(argument);
	
}
		
bool LArguments::compareSignature(std::shared_ptr<LArguments> larg2) const
{
	for(int i = 0; i < arguments.size(); i++)
	{
		if(arguments[i]->getValue().getValue().first != larg2->arguments[i]->getValue().getValue().first)
		{
			return false;
		}
	}
	
	return true;
}

bool LArguments::isForDeclaration() const
{	
	return isForDecl;
}
		
Value LArguments::evaluate() const
{
	return Value();
}

void LArguments::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << std::endl;
	for(int i = 0; i < arguments.size(); i++)
	{
		arguments[i]->printTree(tabulationNumber + 1);
	std::cout << std::endl;
	}
}

void LArguments::buildIR() const
{

}
