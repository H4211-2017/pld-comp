#ifndef FORSTRUCTURE_H
#define FORSTRUCTURE_H

#include "AbstractStructure.h"
#include "Instruction/ComposedInstruction.h"
#include "Instruction/AbstractInstruction.h"


namespace AST {


class ForStructure : public AbstractStructure
{
public:
    ForStructure(std::shared_ptr<ComposedInstruction> condInstr1,
                 std::shared_ptr<ComposedInstruction> condInstr2,
                 std::shared_ptr<ComposedInstruction> condInstr3,
                 std::shared_ptr<AbstractInstruction> intInstruction);

     virtual Value evaluate() const;

     virtual void printTree(int tabulationNumber) const;

     virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

private:
    std::shared_ptr<ComposedInstruction> condInstr1;
    std::shared_ptr<ComposedInstruction> condInstr2;
    std::shared_ptr<ComposedInstruction> condInstr3;
    std::shared_ptr<AbstractInstruction> intInstruction;

};
}
#endif // FORSTRUCTURE_H
