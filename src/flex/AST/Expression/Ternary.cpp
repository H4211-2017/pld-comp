#include "Ternary.h"

using namespace AST;

Ternary::Ternary(std::shared_ptr<AbstractExpression> cond, std::shared_ptr<AbstractExpression> trueBranch, std::shared_ptr<AbstractExpression> falseBranch)
	: AbstractExpression("Ternary")
{
	std::shared_ptr<ComposedInstruction> condif = std::make_shared<ComposedInstruction>(cond);
	std::shared_ptr<ElseStructure> elseFalse = std::make_shared<ElseStructure>(std::make_shared<ComposedInstruction>(falseBranch));
	std::shared_ptr<ComposedInstruction> ifTrue = std::make_shared<ComposedInstruction>(trueBranch);
	
	equivalent = std::make_shared<IfStructure>(condif, ifTrue, elseFalse);
}

void Ternary::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << std::endl;
	equivalent->printTree(tabulationNumber + 1);
}

Value Ternary::evaluate() const
{
		return Value();
}

IR::sh_Memory Ternary::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return equivalent->buildIR(currentBasicBlock);
}
