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
        SequenceInstruction();

        void addInstruction(std::shared_ptr<AbstractInstruction> instruction);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

    private:
        std::vector<std::shared_ptr<AbstractInstruction>> instructionsList;
    };
}

#endif // SEQUENCEINSTRUCTION_H
