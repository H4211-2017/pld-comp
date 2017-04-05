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

/**
 * A FunctionDeclaration is the beginning of a new fonction. Consequently, it will get the basic block of the new function if
 * it is defined, then call the buildIR of its child function with this basic block.
 * If the function is defined but declared, do nothing.
 * @brief FunctionDeclaration::buildIR Build the IR of corresponding to this node
 */
IR::sh_Memory FunctionDeclaration::buildIR(IR::sh_BasicBlock & currentBasicBlock)
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
