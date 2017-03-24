#include "VariableDeclaration.h"
#include "VariableScope.h"

using namespace AST;

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> variableSignature, std::shared_ptr<VariableScope> variableScope)
    : AbstractNode("VariableDeclaration")
{
    variableScope->declareVariable(variableSignature->getIdentifiant(), variableSignature->getValue());
}
