#include "VariableDeclaration.h"
#include "VariableScope.h"

using namespace AST;

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<Scope> scope)
    : AbstractInstruction("VariableDeclaration")
{
	var = std::make_shared<Variable>(signature, true);
    scope->declareVariable(signature->getIdentifiant(), var);
}

VariableDeclaration::VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope)
	: AbstractInstruction("VariableDeclaration"), val(rightMember)
{
	var = std::make_shared<Variable>(signature, false);
    scope->declareVariable(signature->getIdentifiant(), var);
}

void VariableDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    this->var->printTree(tabulationNumber + 1);
    
    if(this->val != nullptr)
    {
		std::cout << std::endl;
		this->val->printTree(tabulationNumber + 1);
    }
}

Value VariableDeclaration::evaluate() const
{
	return Value();
}

IR::sh_Memory VariableDeclaration::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{	
	return nullptr;
}

