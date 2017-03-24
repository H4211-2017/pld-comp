#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "Value.h"
#include "VariableScope.h"
#include "AbstractNode.h"
#include "SequenceInstruction.h"

namespace AST {
	
    class Block : AbstractNode
	{
	public:
        Block();
        Block(std::shared_ptr<VariableScope>, std::shared_ptr<SequenceInstruction>);
		
		
    private:
		std::shared_ptr<SequenceInstruction> sequenceInstr;
	};
	
	
}



#endif // BLOCKNODE_H
