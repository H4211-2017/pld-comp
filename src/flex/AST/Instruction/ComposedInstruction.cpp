#include "ComposedInstruction.h"

using namespace AST;

ComposedInstruction::ComposedInstruction() 
	: AbstractInstruction("ComposedInstruction")
{

}

ComposedInstruction::ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression)
    : AbstractInstruction("ComposedInstruction")
{
    listExpressions.push_back(abstractExpression);
    this->value = abstractExpression->getValue();
}

void ComposedInstruction::addExpression(std::shared_ptr<AbstractExpression> expression)
{
    listExpressions.push_back(expression);
    this->value = expression->getValue();
}

void ComposedInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);

    for (std::shared_ptr<AbstractExpression> expression : listExpressions)
    {
		std::cout << std::endl;
        expression->printTree(tabulationNumber + 1);
    }
}

// TODO
Value ComposedInstruction::evaluate() const
{
	return listExpressions[listExpressions.size()-1]->evaluate();
}

// TODO
void ComposedInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}
