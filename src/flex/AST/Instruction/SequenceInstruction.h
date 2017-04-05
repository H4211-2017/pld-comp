#ifndef SEQUENCEINSTRUCTION_H
#define SEQUENCEINSTRUCTION_H

#include <vector>

#include "AbstractNode.h"
#include "AbstractInstruction.h"

namespace AST {

    class AbstractInstruction;

    class SequenceInstruction : public AbstractNode
    {
    public:
        /**
         * @brief SequenceInstruction constructor, creates an empty sequence of instruction
         */
        SequenceInstruction();

        /**
         * @brief addInstruction
         * @param instruction the instrution to add
         */
        void addInstruction(std::shared_ptr<AbstractInstruction> instruction);

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
        std::vector<std::shared_ptr<AbstractInstruction> > instructionsList;
    };
}

#endif // SEQUENCEINSTRUCTION_H
