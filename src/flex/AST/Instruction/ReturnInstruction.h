#ifndef RETURNINSTRUCTION_H
#define RETURNINSTRUCTION_H

#include "AbstractNode.h"

#include <memory>

#include "Instruction/ComposedInstruction.h"

namespace AST 
{

    class ReturnInstruction : public AbstractNode
    {
    
    public:
		/**
         * @brief ReturnInstruction constructor
         */
        ReturnInstruction();
        
        /**
         * @brief ReturnInstruction constructor
         * @param composedInstruction a shared_ptr to the composedInstruction evaluated as the return value
         */
        ReturnInstruction(std::shared_ptr<ComposedInstruction> composedInstruction);
        
        /**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
		virtual void printTree(int tabulationNumber) const;
		
		/**
		 * @brief evaluate pure virtual function
		 * @return the "Value" of the expression, mainly it's type.
		 */
        virtual Value evaluate() const;
        
        /**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
		std::shared_ptr<ComposedInstruction> composedInstruction;
    };
}

#endif // RETURNINSTRUCTION_H
