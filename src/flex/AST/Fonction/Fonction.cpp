#include "Fonction.h"

#include <sstream>
#include <iostream>

using namespace AST;

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature)
	: AbstractInstruction("Fonction")
{
	sig = signature;
	this->setType(sig->getValue().getValue().first);
	args = nullptr;
	content = nullptr;
}

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments)
	: Fonction(signature)
{
	args = arguments;
}

Fonction::Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content)
	: Fonction(signature, arguments)
{
	this->content = content;
	if(args->isForDeclaration())
	{
		std::stringstream ss;
		ss << "ERROR in definition of function <" << sig->getIdentifiant() << "> : one or more parameter is unnamed.";
		std::cerr << ss.str() << std::endl;
		exit(-1);
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

bool Fonction::isDeclaration() const
{
	return content == nullptr;
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
