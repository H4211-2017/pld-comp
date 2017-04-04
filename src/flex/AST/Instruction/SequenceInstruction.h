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
         * @brief SequenceInstruction construtor, creates and empty sequence of instruction
         */
        SequenceInstruction();

        /**
         * @brief addInstruction
         * @param instruction the instrution to add
         */
        void addInstruction(std::shared_ptr<AbstractInstruction> instruction);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock);

    private:
        std::vector<std::shared_ptr<AbstractInstruction>> instructionsList;
    };
}

#endif // SEQUENCEINSTRUCTION_H
