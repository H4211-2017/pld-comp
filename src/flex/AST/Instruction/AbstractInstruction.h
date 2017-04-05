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

/**
 * @brief Dynamically turn a polymorphed pointer on AbstractInstruction into a shared_pointer
 * @param ptr AST::AbstractInstruction* a polymorphed pointer to a subclass of AbstractInstruction
 * @return a shared pointer to an AbstractInstruction
 */
std::shared_ptr<AST::AbstractInstruction> make_shared_instr(AST::AbstractInstruction* ptr);

#endif // AST_ABSTRACTINSTRUCTION_H
