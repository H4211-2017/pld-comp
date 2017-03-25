#include "VariableDeclaration.h"
#include "VariableScope.h"

using namespace AST;

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<VariableScope> variableScope)
    : AbstractInstruction("VariableDeclaration"), sig(signature)
{
    variableScope->declareVariable(signature->getIdentifiant(), nullptr);
}

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<VariableScope> variableScope)
	: AbstractInstruction("VariableDeclaration"), sig(signature), val(rightMember)
{
	variableScope->declareVariable(signature->getIdentifiant(), rightMember);
	rightMember->setType(signature->getValue().getValue().first);
}

void VariableDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    this->sig->printTree(tabulationNumber + 1);
    
    if(this->val != nullptr)
    {
		std::cout << std::endl;
		this->val->printTree(tabulationNumber + 1);
    }

}

Value VariableDeclaration::evaluate() const
{
	return Value();
}

void VariableDeclaration::buildIR() const
{

}

