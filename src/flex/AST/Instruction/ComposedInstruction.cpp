#include "ComposedInstruction.h"

using namespace AST;

ComposedInstruction::ComposedInstruction() 
	: ComposedInstruction("ComposedInstruction")
{

}

ComposedInstruction::ComposedInstruction(std::string name)
	: AbstractInstruction(name)
{
	
}

ComposedInstruction::ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression)
    : ComposedInstruction("ComposedInstruction")
{
    listExpressions.push_back(abstractExpression);
    this->value = abstractExpression->getValue();
}

void ComposedInstruction::addExpression(std::shared_ptr<AbstractExpression> expression)
{
    listExpressions.push_back(expression);
    this->value = expression->getValue();
}

std::vector<std::shared_ptr<AbstractExpression>> ComposedInstruction::getListExpr() const
{
	return listExpressions;
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


IR::sh_Memory ComposedInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{
	IR::sh_Memory lastMemory = nullptr;
	
    for(std::shared_ptr<AbstractExpression> expression : listExpressions)
    {
		if (expression != nullptr)
		{
			lastMemory = expression->buildIR(currentBasicBlock);
		}
    }
    
	return lastMemory;
}
