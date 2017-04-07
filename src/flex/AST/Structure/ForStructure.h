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
    * @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
    * @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
    * 		that is currently being completed
    * @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
    * 		shouldn't be callable
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
