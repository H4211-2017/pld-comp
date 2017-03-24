#ifndef ABSTRACTINSTRUCTION_H
#define ABSTRACTINSTRUCTION_H

#include "AbstractNode.h"
#include <memory>

namespace AST 
{

    class AbstractInstruction : public AbstractNode
    {
    
    public:
        AbstractInstruction(std::string name);
        
    };
}

std::shared_ptr<AST::AbstractInstruction> make_shared_instr(AST::AbstractInstruction* ptr);

#endif // ABSTRACTINSTRUCTION_H