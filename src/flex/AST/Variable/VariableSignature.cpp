#include "VariableSignature.h"

using namespace AST;

VariableSignature::VariableSignature(std::string identifiant, Type type)
    : AbstractNode("VariableSignature", type), identifiant(identifiant)
{

}

void VariableSignature::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

    if(identifiant != "")
    {
        std::cout << " | Variable name : " << identifiant;
    }
}

Value VariableSignature::evaluate() const
{

}

IR::sh_Memory VariableSignature::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return nullptr;
}

std::string VariableSignature::getIdentifiant() const
{
    return identifiant;
}

Value VariableSignature::getValue() const
{
    return value;
}

