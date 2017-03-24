#include "ArgumentList.h"

using namespace AST;

ArgumentList::ArgumentList(VariableSignature variableSignature)
    : AbstractNode("ArgumentList")
{
    variableSignatureList.push_back(variableSignature);
}

ArgumentList::ArgumentList(VariableSignature variableSignature, ArgumentList argumentList)
    : AbstractNode("ArgumentList"), variableSignatureList(argumentList.variableSignatureList)
{
    variableSignatureList.push_back(variableSignature);
}

void ArgumentList::printTree(int tabulationNumber) const
{

}

Value ArgumentList::evaluate() const
{

}

void ArgumentList::buildIR() const
{

}
