#include "VariableDeclaration.h"
#include "VariableScope.h"

using namespace AST;

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<VariableScope> variableScope)
    : AbstractInstruction("VariableDeclaration")
{
    variableScope->declareVariable(signature->getIdentifiant(), nullptr);
}

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<VariableScope> variableScope)
	: AbstractInstruction("VariableDeclaration")
{
	variableScope->declareVariable(signature->getIdentifiant(), rightMember);
}

void VariableDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

}

Value VariableDeclaration::evaluate() const
{
	return Value();
}

void VariableDeclaration::buildIR() const
{

}

