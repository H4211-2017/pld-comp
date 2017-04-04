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
        ReturnInstruction();
        ReturnInstruction(std::shared_ptr<ComposedInstruction> composedInstruction);
        
		virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock);
        
    private:
		std::shared_ptr<ComposedInstruction> composedInstruction;
    };
}

#endif // RETURNINSTRUCTION_H
