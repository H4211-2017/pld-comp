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
         * @param name the name of the structure we are creating, used when printing the tree.
         */
		AbstractStructure(std::string name);
	};

}


std::shared_ptr<AST::AbstractStructure> make_shared_struct(AST::AbstractStructure *ptr);

#endif // ABSTRACTSTRUCTURE_H
