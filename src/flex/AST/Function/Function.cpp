#include "Function.h"

#include "LParametres.h"

#include <sstream>
#include <iostream>

using namespace AST;

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Scope> parentScope)
    : AbstractNode("Function")
{
	currentScope = std::make_shared<Scope>(parentScope);
	sig = signature;
	this->setType(sig->getValue().getValue().first);
	args = nullptr;
	content = nullptr;
	irFunction = std::make_shared<IR::ExternalFunction>(signature->getIdentifiant());
}

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Scope> parentScope)
    : Function(signature, parentScope)
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

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope)
    : Function(signature, parentScope)
{
	currentScope = std::make_shared<Scope>(parentScope);
	this->setBlock(content);
}

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope)
    : Function(signature, arguments, parentScope)
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

std::shared_ptr<IR::ExternalFunction> Function::getIrFunction()
{
	return irFunction;
}

bool Function::compareArguments(std::shared_ptr<Function> f2) const
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

bool Function::checkParametres(std::shared_ptr<LParametres> params) const
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

bool Function::isDeclaration() const
{
	return content == nullptr;
}

void Function::setBlock(std::shared_ptr<Block> content)
{
	this->content = content;
}

std::shared_ptr<FunctionSignature> Function::getSignature() const
{
	return sig;
}
        
void Function::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
    std::cout << "| Name function : " << sig->getIdentifiant() << std::endl;

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

Value Function::evaluate() const
{
	return Value();
}

IR::sh_Memory Function::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}
 
