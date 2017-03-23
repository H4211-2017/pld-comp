#include "VariableSignature.h"

using namespace AST;

VariableSignature::VariableSignature(std::string identifiant, Type type)
    : AbstractNode(type), identifiant(identifiant)
{

}

void VariableSignature::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

}

Value VariableSignature::evaluate() const
{

}

void VariableSignature::buildIR() const
{

}

std::string VariableSignature::getIdentifiant() const
{
    return identifiant;
}

Value VariableSignature::getValue() const
{
    return value;
}
