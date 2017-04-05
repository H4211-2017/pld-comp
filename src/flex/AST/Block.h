#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "Value.h"
#include "Scope.h"
#include "AbstractNode.h"
#include "Instruction/SequenceInstruction.h"

namespace AST
{
    class Block : public AbstractNode
	{
	public:
	
		/**
         * @brief Block constructor
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
         * @return the value of its sequence of instructions
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
		* @return a shared pointer to the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

		/**
         * @brief get a reference to the most local Scope for the node
         * @return a shared pointer to the Scope object
         */
        virtual std::shared_ptr<Scope> getScope() const;
     
    private:
    	
        std::shared_ptr<SequenceInstruction> sequenceInstruction;
	};
}



#endif // BLOCKNODE_H
