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
         * @brief SequenceInstruction default constructor, creates an empty sequence of instruction
         */
        SequenceInstruction();

        /**
         * @brief addInstruction add instruction in the sequence
         * @param instruction the instrution to add
         */
        void addInstruction(std::shared_ptr<AbstractInstruction> instruction);

		/**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
        
        /**
         * @brief evaluate the Value of this node
         * @return the value of the last instruction of the instance, if evaluable, or error null value otherwise
         */
        virtual Value evaluate() const;
        
        /**
		 * @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		 * @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		 * @return a nullptr (return deprecated here)
		 */
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

    private:
    
        std::vector<std::shared_ptr<AbstractInstruction> > instructionsList;
    };
}

#endif // SEQUENCEINSTRUCTION_H
