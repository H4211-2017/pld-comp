#include "Variable.h"

#include <sstream>
#include <iostream>

using namespace AST;

Variable::Variable(std::shared_ptr<VariableSignature> signature, bool decl, const IR::Generator &generator)
	: AbstractVariable("Variable", signature, decl)
{
	switch(signature->getValue().getValue().first)
	{
		case CHAR :
			memory = generator.getNewUnusedMemmory(IR::CHAR);
			break;
		case INT_32 :
			memory = generator.getNewUnusedMemmory(IR::INT_32);
			break;
		case INT_64 :
			memory = generator.getNewUnusedMemmory(IR::INT_64);
			break;
		default :
			std::cerr << "ERROR Constructor Variable : Error in value of type : " << value.getValue().first << "Of Variable " << signature->getName() << std::endl;
			break;
	}
	sig = signature;
	this->setType(sig->getValue().getValue().first);
}

Variable::Variable(std::string name, std::shared_ptr<VariableSignature> signature, bool decl)
    : AbstractVariable(name, signature, decl)
{
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

void Variable::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}
