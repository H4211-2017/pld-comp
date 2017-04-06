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
        
		/**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once executed
		* 		or nullptr if the node shouldn't be calculated to be a value
		*/
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
        
    };
}

/**
 * @brief Dynamically turn a polymorphed pointer on AbstractInstruction into a shared_pointer
 * @param ptr AST::AbstractInstruction* a polymorphed pointer to a subclass of AbstractInstruction
 * @return a shared pointer to an AbstractInstruction
 */
std::shared_ptr<AST::AbstractInstruction> make_shared_instr(AST::AbstractInstruction* ptr);

#endif // AST_ABSTRACTINSTRUCTION_H
