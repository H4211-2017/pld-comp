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
}

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Scope> parentScope)
    : Function(signature, parentScope)
{
    args = arguments;
}

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope)
    : Function(signature, parentScope)
{
    irFunction = std::make_shared<IR::FunctionBlock>(signature->getIdentifiant());
    content = content;
}

Function::Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope)
    : Function(signature, content, parentScope)
{
    args = arguments;
	if(args != nullptr && args->isForDeclaration())
	{
		std::stringstream ss;
		ss << "ERROR in definition of function <" << sig->getIdentifiant() << "> : one or more parameter is unnamed.";
        throw std::runtime_error(ss.str());
	}
    args->prepareScope(currentScope);
}

std::shared_ptr<IR::FunctionBlock> Function::getIrFunction()
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


// TODO : Check comportment with declaration then definition
std::shared_ptr<IR::FunctionBlock> Function::getIrFunction() const
{
    if (irFunction  == nullptr)
    {
        std::stringstream ss;
        ss << "Compilation error : function used but not defined : " << sig->getIdentifiant() << std::endl;
        throw std::runtime_error(ss.str());
    }
    return irFunction;
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
 
