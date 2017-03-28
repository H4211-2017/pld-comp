#include "WhileStructure.h"

using namespace AST;

WhileStructure::WhileStructure(std::shared_ptr<ComposedInstruction> condition,
                               std::shared_ptr<AbstractInstruction> instruction)
    :AbstractStructure("WhileStructure")
{
    this->condition = condition;
    this->intInstruction = instruction;
}

Value WhileStructure::evaluate() const
{
    return value;
}

void WhileStructure::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    if(condition != nullptr)
    {
        std::cout << std::endl;
        condition->printTree(tabulationNumber + 1);
    }
    if(intInstruction != nullptr)
    {
        std::cout << std::endl;
        intInstruction->printTree(tabulationNumber + 1);
    }

}

void WhileStructure::buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const
{

}
