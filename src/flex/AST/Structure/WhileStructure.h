#ifndef WHILESTRUCT_H
#define WHILESTRUCT_H

#include "AbstractStructure.h"
#include "Instruction/ComposedInstruction.h"
#include "Instruction/AbstractInstruction.h"

namespace AST{
class WhileStructure : public AbstractStructure
{
public:
    WhileStructure(std::shared_ptr<ComposedInstruction> condition,
                std::shared_ptr<AbstractInstruction> intInstruction);

    virtual Value evaluate() const;

    virtual void printTree(int tabulationNumber) const;

    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    std::shared_ptr<ComposedInstruction> condition;
    std::shared_ptr<AbstractInstruction> intInstruction;
};
}

#endif // WHILESTRUCT_H
