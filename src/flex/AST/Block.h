#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include "Value.h"
#include "Scope.h"
#include "AbstractNode.h"
#include "Instruction/SequenceInstruction.h"

namespace AST {
	
    class Block : public AbstractNode
	{
	public:
        Block();
        Block(std::shared_ptr<Scope>, std::shared_ptr<SequenceInstruction>);

        /**
         * @brief evaluate the Value of this node
         * @return the value of its sequence of instructions
         */
        virtual Value evaluate() const;

        /**
         * @brief printTree the tree corresponding to this node and it's children.
         * @param tabulationNumber the tabulation of this current node.
         */
        virtual void printTree(int tabulationNumber) const;

        /**
         * @brief buildIR builds the blocs corresponding to this bloc, and it's children.
         */
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

        virtual std::shared_ptr<Scope> getScope() const;
     
    private:
    	
        std::shared_ptr<SequenceInstruction> sequenceInstruction;
	};
	
	
}



#endif // BLOCKNODE_H
