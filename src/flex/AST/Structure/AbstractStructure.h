#ifndef ABSTRACTSTRUCTURE_H
#define ABSTRACTSTRUCTURE_H

#include "AbstractNode.h"

#include "../../../IR/data/Memory.h"

namespace AST
{
    
	class AbstractStructure : public AbstractNode
	{
		
	public:
        /**
         * @brief AbstractStructure constructor of an Abstract structure.
         * @param name the type of the node created, used when printing the tree.
         */
		AbstractStructure(std::string name);
		
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
 * @brief Dynamically turn a polymorphed pointer on AbstractStructure into a shared_pointer
 * @param ptr AST::AbstractExpression* a polymorphed pointer to a subclass of AbstractStructure
 * @return a shared pointer to an AbstractStructure
 */
std::shared_ptr<AST::AbstractStructure> make_shared_struct(AST::AbstractStructure *ptr);

#endif // ABSTRACTSTRUCTURE_H
