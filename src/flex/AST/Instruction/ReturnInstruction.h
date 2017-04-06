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
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
		virtual void printTree(int tabulationNumber) const;
		
		/**
		 * @brief return the Value of return of associated function if it is determinist or a null error-type Value otherwise
		 * @return the value corresponding
		 */
        virtual Value evaluate() const;
        
        /**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the return value once executed
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
		std::shared_ptr<ComposedInstruction> composedInstruction;
    };
}

#endif // RETURNINSTRUCTION_H
