#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "Value.h"
#include "VariableScope.h"
#include "AbstractNode.h"
#include "SequenceInstruction.h"

namespace AST {
	
	class BlockNode : AbstractNode
	{
	public:
		BlockNode();
		BlockNode(std::shared_ptr<VariableScope>, std::shared_ptr<SequenceInstruction>);
		
		
	protected:
		std::shared_ptr<SequenceInstruction> sequenceInstr;
		
		
	};
	
	
}



#endif // BLOCKNODE_H
