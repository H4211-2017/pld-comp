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

std::shared_ptr<IR::FunctionBlock> FunctionDeclaration::getIrFunction() const
{
    return fct->getIrFunction();
}

void FunctionDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

    std::cout << std::endl;
    if(this->fct != nullptr) {
        this->fct->printTree(tabulationNumber + 1);
    }
}

Value FunctionDeclaration::evaluate() const
{
    return Value();
}

IR::sh_Memory FunctionDeclaration::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{

}
