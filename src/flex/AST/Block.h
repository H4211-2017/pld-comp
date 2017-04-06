#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "AbstractNode.h"

#include "Value.h"
#include "Scope.h"
#include "Instruction/SequenceInstruction.h"

namespace AST
{
    class Block : public AbstractNode
	{
	public:
	
		/**
         * @brief default Block constructor, create a void block
         */
        Block();
        
        /**
         * @brief Block constructor
         * @param scope a shared_ptr to the current Scope
         * @param instr a shared_ptr to the list of instruction inside the Block
         */
        Block(std::shared_ptr<Scope>, std::shared_ptr<SequenceInstruction>);

        /**
         * @brief evaluate the Value of this node
         * @return the value of its sequence of instructions or error null value
         * if the block has no instruction inside
         */
        virtual Value evaluate() const;

		 /**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;

        /**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once executed
		* 		or nullptr if the node shouldn't be calculated to be a value
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

        /**
         * @brief get a reference on the most local Scope for the node
         * @return a shared pointer on the Scope object
         */
        virtual std::shared_ptr<Scope> getScope() const;
     
    private:
    	
        std::shared_ptr<SequenceInstruction> sequenceInstruction;
	};
}

#endif // BLOCKNODE_H
