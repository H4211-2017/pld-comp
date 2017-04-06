#include "VariableDeclaration.h"

#include "VariableScope.h"
#include "../../../IR/generator/Generator.h"

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
	IR::Generator gen;
	
	IR::sh_Memory dest = var->buildIR(currentBasicBlock);
	IR::sh_Memory value = nullptr;
	
	// if definition of variable instead declaration
	if (val != nullptr)
	{
		// such as AffectationExrpession::buildIR
		value = val->buildIR(currentBasicBlock);
		std::list<IR::sh_AbsInstruction> absIntructions = gen.setValue(value, dest);
		currentBasicBlock->pushInstructionBack(absIntructions); 
	}
	
	return value;
}

