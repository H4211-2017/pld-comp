#include "ArrayDeclaration.h"
#include "VariableScope.h"

using namespace AST;

ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> size, std::shared_ptr<Scope> scope)
    : AbstractDeclaration("ArrayDeclaration", signature), size(size)
{
    scope->declareVariable(signature->getIdentifiant(), nullptr);
}

void ArrayDeclaration::printTree(int tabulationNumber) const
{
    AbstractDeclaration::printTree(tabulationNumber);
       
    if(this->val != nullptr)
    {
		std::cout << std::endl;
		this->val->printTree(tabulationNumber + 1);
    }

}

Value ArrayDeclaration::evaluate() const
{
	return Value();
}

void ArrayDeclaration::buildIR() const
{

}

