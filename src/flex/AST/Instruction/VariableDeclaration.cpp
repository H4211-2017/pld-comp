#include "VariableDeclaration.h"
#include "VariableScope.h"

using namespace AST;

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<Scope> scope)
    : AbstractDeclaration("VariableDeclaration", signature)
{
    scope->declareVariable(signature->getIdentifiant(), nullptr);
}

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope)
	: AbstractDeclaration("VariableDeclaration", signature), val(rightMember)
{
	scope->declareVariable(signature->getIdentifiant(), rightMember);
	rightMember->setType(signature->getValue().getValue().first);
}

void VariableDeclaration::printTree(int tabulationNumber) const
{
    AbstractDeclaration::printTree(tabulationNumber);
       
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

