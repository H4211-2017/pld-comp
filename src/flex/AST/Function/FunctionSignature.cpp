#include "FunctionSignature.h"

using namespace AST;

FunctionSignature::FunctionSignature(std::string identifiant)
    : AbstractNode("FunctionSignature"), identifiant(identifiant)
{

}

FunctionSignature::FunctionSignature(std::string identifiant, Type type)
    : AbstractNode("FunctionSignature", type), identifiant(identifiant)
{

}

void FunctionSignature::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

}

Value FunctionSignature::evaluate() const
{

}

void FunctionSignature::buildIR() const
{

}

std::string FunctionSignature::getIdentifiant() const
{
    return identifiant;
}

Value FunctionSignature::getValue() const
{
    return value;
}

