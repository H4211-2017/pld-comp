s#include "FonctionSignature.h"

using namespace AST;

FonctionSignature::FonctionSignature(std::string identifiant)
    : AbstractNode("FonctionSignature"), identifiant(identifiant)
{

}

FonctionSignature::FonctionSignature(std::string identifiant, Type type)
    : AbstractNode("FonctionSignature", type), identifiant(identifiant)
{

}

void FonctionSignature::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

}

Value FonctionSignature::evaluate() const
{

}

void FonctionSignature::buildIR() const
{

}

std::string FonctionSignature::getIdentifiant() const
{
    return identifiant;
}

Value FonctionSignature::getValue() const
{
    return value;
}

