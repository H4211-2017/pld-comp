#include "ForStructure.h"

using namespace AST;

ForStructure::ForStructure(std::shared_ptr<ComposedInstruction> cond1,
                           std::shared_ptr<ComposedInstruction> cond2,
                           std::shared_ptr<ComposedInstruction> cond3,
                           std::shared_ptr<AbstractInstruction> instr)
    :AbstractStructure("ForStructure")
{
    condInstr1 = cond1;
    condInstr2 = cond2;
    condInstr3 = cond3;
    intInstruction = instr;
}

Value ForStructure::evaluate() const
{
        return value;
}

void ForStructure::printTree(int tabulationNumber) const
{
        AbstractNode::printTree(tabulationNumber);
        if(condInstr1 != nullptr)
        {
                std::cout << std::endl;
                condInstr1->printTree(tabulationNumber + 1);
        }
        if(condInstr2 != nullptr)
        {
                std::cout << std::endl;
                condInstr2->printTree(tabulationNumber + 1);
        }
        if(condInstr3 != nullptr)
        {
                std::cout << std::endl;
                condInstr3->printTree(tabulationNumber + 1);
        }
        if(intInstruction != nullptr)
        {
                std::cout << std::endl;
                intInstruction->printTree(tabulationNumber + 1);
        }
}

void ForStructure::buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const
{

}
