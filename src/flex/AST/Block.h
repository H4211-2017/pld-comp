#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "Value.h"
#include "VariableScope.h"
#include "AbstractNode.h"
#include "Instruction/SequenceInstruction.h"

namespace AST {
	
    class Block : public AbstractNode
	{
	public:
        Block();
        Block(std::shared_ptr<VariableScope>, std::shared_ptr<SequenceInstruction>);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;

        virtual std::shared_ptr<VariableScope> getScope() const;
     
    private:
    	
        std::shared_ptr<SequenceInstruction> sequenceInstruction;
	};
	
	
}



#endif // BLOCKNODE_H
