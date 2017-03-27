#include "AbstractDeclaration.h"

using namespace AST;

AbstractDeclaration::AbstractDeclaration(std::string name, std::shared_ptr<VariableSignature> signature)
    : AbstractInstruction(name), sig(signature)
{

}

void AbstractDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    this->sig->printTree(tabulationNumber + 1);
}

Value AbstractDeclaration::evaluate() const
{
	return Value();
}

