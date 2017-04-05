
#ifndef PROGRAM_NODE_H
#define PROGRAM_NODE_H


#include "AbstractNode.h"

namespace AST {
	
	class FunctionDeclaration;
	class SequenceInstruction;
	
    class ProgramNode : public AbstractNode
    {
    public:
    
        ProgramNode(std::shared_ptr<SequenceInstruction> liextBefore, std::shared_ptr<FunctionDeclaration> main, std::shared_ptr<SequenceInstruction> liextAfter);
		
		 /**
         * @brief printTree the tree corresponding to this node and it's children.
         * @param tabulationNumber the tabulation of this current node.
         */
        virtual void printTree(int tabulationNumber) const;
        
        /**
         * @brief evaluate the Value of this node
         * @return the value of its sequence of instructions
         */
        virtual Value evaluate() const;
        
         /**
         * @brief buildIR builds the blocs corresponding to this bloc, and it's children.
         */
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
        std::shared_ptr<SequenceInstruction> liextBefore;
        std::shared_ptr<SequenceInstruction> liextAfter;
        std::shared_ptr<FunctionDeclaration> main;

    };
}


#endif // PROGRAM_NODE_H
