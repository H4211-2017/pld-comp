#ifndef SEQUENCEINSTRUCTION_H
#define SEQUENCEINSTRUCTION_H

#include <vector>

#include "AbstractNode.h"
#include "AbstractInstruction.h"

namespace AST {
    class SequenceInstruction : public AbstractNode
    {
    public:
        SequenceInstruction(std::shared_ptr<AbstractInstruction> instruction);
        SequenceInstruction(std::shared_ptr<SequenceInstruction> sequenceInstruction, std::shared_ptr<AbstractInstruction> instruction);

    private:
        std::vector<std::shared_ptr<AbstractInstruction>> instructionsList;
    };
}

#endif // SEQUENCEINSTRUCTION_H
