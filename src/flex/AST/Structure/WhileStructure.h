#ifndef WHILESTRUCT_H
#define WHILESTRUCT_H

#include "AbstractStructure.h"
#include "Instruction/ComposedInstruction.h"
#include "Instruction/AbstractInstruction.h"

namespace AST{

class WhileStructure : public AbstractStructure
{
public:

    /**
     * @brief WhileStructure constructor
     * @param condition instruction condition of this controle structure
     * @param intInstruction the instructions executed in the loop
     */
    WhileStructure(std::shared_ptr<ComposedInstruction> condition,
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

protected:
    std::shared_ptr<ComposedInstruction> condition;
    std::shared_ptr<AbstractInstruction> intInstruction;
};
}

#endif // WHILESTRUCT_H
