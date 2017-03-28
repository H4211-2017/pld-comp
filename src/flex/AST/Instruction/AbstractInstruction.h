#ifndef AST_ABSTRACTINSTRUCTION_H
#define AST_ABSTRACTINSTRUCTION_H

#include "AbstractNode.h"
#include <memory>

namespace AST 
{

    class AbstractInstruction : public AbstractNode
    {
    
    public:
        /**
         * @brief AbstractInstruction constructor
         * @param name the name of the node
         */
        AbstractInstruction(std::string name);
        
    };
}

std::shared_ptr<AST::AbstractInstruction> make_shared_instr(AST::AbstractInstruction* ptr);

#endif // AST_ABSTRACTINSTRUCTION_H
