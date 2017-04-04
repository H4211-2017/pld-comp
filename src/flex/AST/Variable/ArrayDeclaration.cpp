#include "ArrayDeclaration.h"

#include "VariableSignature.h"
#include "Array.h"
#include "Scope.h"

using namespace AST;

ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
		long int size, std::shared_ptr<Scope> scope)
		: AbstractInstruction("ArrayDeclaration")
{	
	array = std::make_shared<Array>(signature, size);
	scope->declareVariable(signature->getIdentifiant(), array);
}

void ArrayDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    this->array->printTree(tabulationNumber + 1);
}

Value ArrayDeclaration::evaluate() const
{
	return Value();
}

void ArrayDeclaration::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}

