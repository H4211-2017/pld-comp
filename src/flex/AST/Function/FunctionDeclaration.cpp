#include "FunctionDeclaration.h"
#include "Scope.h"

using namespace AST;

FunctionDeclaration::FunctionDeclaration(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Function> function, std::shared_ptr<Scope> scope)
    : AbstractInstruction("FunctionDeclaration")
{
    sig = signature;
    fct = function;
    scope->declareFunction(sig->getIdentifiant(), fct);
}

std::string FunctionDeclaration::getIdentifiant() const
{
   return fct->getSignature()->getIdentifiant();
}

std::shared_ptr<IR::FunctionBlock> FunctionDeclaration::getIrFunction() const
{
    return fct->getIrFunction();
}

bool FunctionDeclaration::isDeclaration() const
{
    return fct->isDeclaration();
}

void FunctionDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

    std::cout << std::endl;
    if(this->fct != nullptr)
    {
        this->fct->printTree(tabulationNumber + 1);
    }
}

Value FunctionDeclaration::evaluate() const
{
    return Value();
}

IR::sh_Memory FunctionDeclaration::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    // Build something only if the function is declared.
    if (!fct->isDeclaration())
    {
        IR::sh_BasicBlock functionCore = fct->getIrFunction()->getFunctionCore();
        fct->buildIR(functionCore);
    }
    // TODO check if a return value (return fct->buildIR(functionCore)) is needed
    return nullptr;
}
