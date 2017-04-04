#ifndef FORSTRUCTURE_H
#define FORSTRUCTURE_H

#include "AbstractStructure.h"
#include "Instruction/ComposedInstruction.h"
#include "Instruction/AbstractInstruction.h"


namespace AST {


class ForStructure : public AbstractStructure
{
public:
    /**
     * @brief ForStructure constructor
     * @param condInstr1 init instruction
     * @param condInstr2 condition instruction
     * @param condInstr3 incrementation instruction
     * @param intInstruction the instructions in the loop
     */
    ForStructure(std::shared_ptr<ComposedInstruction> condInstr1,
                 std::shared_ptr<ComposedInstruction> condInstr2,
                 std::shared_ptr<ComposedInstruction> condInstr3,
                 std::shared_ptr<AbstractInstruction> intInstruction);

    /**
     * @brief evaluate the Value of this node
     * @return a Value of Type error that = 0
     */
     virtual Value evaluate() const;

    /**
     * @brief printTree the tree corresponding to this node and it's children.
     * @param tabulationNumber the tabulation of this current node.
     */
    virtual void printTree(int tabulationNumber) const;

    /**
     * @brief buildIR builds the blocs corresponding to this bloc, and it's children.
     */
     virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

private:
    std::shared_ptr<ComposedInstruction> condInstr1;
    std::shared_ptr<ComposedInstruction> condInstr2;
    std::shared_ptr<ComposedInstruction> condInstr3;
    std::shared_ptr<AbstractInstruction> intInstruction;

};
}
#endif // FORSTRUCTURE_H
