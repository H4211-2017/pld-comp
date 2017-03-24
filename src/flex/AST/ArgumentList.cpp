#include "ArgumentList.h"

using namespace AST;

ArgumentList::ArgumentList(std::shared_ptr<VariableSignature> variableSignature)
    : AbstractNode("ArgumentList")
{
    variableSignatureList.push_back(variableSignature);
}

void ArgumentList::addArgument(std::shared_ptr<VariableSignature> argument)
{
    variableSignatureList.push_back(argument);
}

bool ArgumentList::checkValidForFunctionDefinition() const
{
    for (std::shared_ptr<VariableSignature> variableSignature : variableSignatureList)
    {
        if (variableSignature->getIdentifiant() == "")
        {
            return false;
        }
    }
    return true;
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
