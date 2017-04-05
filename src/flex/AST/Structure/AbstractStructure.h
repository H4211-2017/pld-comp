#ifndef ABSTRACTSTRUCTURE_H
#define ABSTRACTSTRUCTURE_H

#include "AbstractNode.h"

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
	};

}

/**
 * @brief Dynamically turn a polymorphed pointer on AbstractStructure into a shared_pointer
 * @param ptr AST::AbstractExpression* a polymorphed pointer to a subclass of AbstractStructure
 * @return a shared pointer to an AbstractStructure
 */
std::shared_ptr<AST::AbstractStructure> make_shared_struct(AST::AbstractStructure *ptr);

#endif // ABSTRACTSTRUCTURE_H
