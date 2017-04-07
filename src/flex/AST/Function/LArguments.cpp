#include "LArguments.h"

#include <iostream>
#include <sstream>

#include "Scope.h"
#include "Variable/Variable.h"
#include "LParametres.h"

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
	if(larg2 == nullptr)
	{
		return false;
	}

	for(int i = 0; i < arguments.size(); i++)
	{
		if(arguments[i]->getValue().getValue().first != larg2->arguments[i]->getValue().getValue().first)
		{
			return false;
		}
	}
	
	return true;
}

bool LArguments::checkParametres(std::shared_ptr<LParametres> params) const
{
	if(params == nullptr)
	{
		
		return arguments.size() == 0;
	}
	if(arguments.size() == params->parameters.size())
	{
		return true;
	}
	return false;
}

bool LArguments::isForDeclaration() const
{	
	return isForDecl;
}

void LArguments::prepareScope(std::shared_ptr<Scope> scope) const
{
	for(int i=0; i < arguments.size(); i++)
	{
		scope->declareVariable(arguments[i]->getIdentifiant(), std::make_shared<Variable>(arguments[i], false));
	}
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

std::vector<std::shared_ptr<VariableSignature> > LArguments::getArguments()
{
    return arguments;
}

IR::sh_Memory LArguments::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}
