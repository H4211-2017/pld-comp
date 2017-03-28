#include "Fonction.h"

#include "LParametres.h"

#include <sstream>
#include <iostream>

using namespace AST;

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<Scope> parentScope)
	: AbstractNode("Fonction")
{
	currentScope = std::make_shared<Scope>(parentScope);
	sig = signature;
	this->setType(sig->getValue().getValue().first);
	args = nullptr;
	content = nullptr;
}

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Scope> parentScope)
	: Fonction(signature, parentScope)
{
	args = arguments;
	if(args != nullptr && args->isForDeclaration())
	{
		std::stringstream ss;
		ss << "ERROR in definition of function <" << sig->getIdentifiant() << "> : one or more parameter is unnamed.";
		std::cerr << ss.str() << std::endl;
		exit(-1);
	}
	else if(!args->isForDeclaration())
	{
		args->prepareScope(currentScope);
	}
}

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope)
	: Fonction(signature, parentScope)
{
	currentScope = std::make_shared<Scope>(parentScope);
	this->setBlock(content);
}

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope)
	: Fonction(signature, arguments, parentScope)
{
	
	currentScope = std::make_shared<Scope>(parentScope);
		
	this->setBlock(content);
	if(args != nullptr && args->isForDeclaration())
	{
		std::stringstream ss;
		ss << "ERROR in definition of function <" << sig->getIdentifiant() << "> : one or more parameter is unnamed.";
		std::cerr << ss.str() << std::endl;
		exit(-1);
	}
	else if(!args->isForDeclaration())
	{
		args->prepareScope(currentScope);
	}
}

bool Fonction::compareArguments(std::shared_ptr<Fonction> f2) const
{
	if(args == nullptr ^ f2->args == nullptr)
	{
		return false;
	}
	else if(args == nullptr && f2->args == nullptr)
	{
		return true;
	}
	return args->compareSignature(f2->args);
}

bool Fonction::checkParametres(std::shared_ptr<LParametres> params) const
{
	if(args == nullptr && params == nullptr)
	{
		return true;
	}
	else if(args == nullptr)
	{
		return params->parametres.size() == 0;
	}
	return args->checkParametres(params);
	
}

bool Fonction::isDeclaration() const
{
	return content == nullptr;
}

void Fonction::setBlock(std::shared_ptr<Block> content)
{
	
	this->content = content;
}

std::shared_ptr<FonctionSignature> Fonction::getSignature() const
{
	return sig;
}
        
void Fonction::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << std::endl;
	sig->printTree(tabulationNumber + 1);
	if(args != nullptr)
	{
		std::cout << std::endl;
		args->printTree(tabulationNumber + 1);
	}
	if(content != nullptr)
	{
		std::cout << std::endl;
		content->printTree(tabulationNumber + 1);
	}
}

Value Fonction::evaluate() const
{
	return Value();
}

void Fonction::buildIR() const
{

}
