
#ifndef PROGRAM_NODE_H
#define PROGRAM_NODE_H

#include "AbstractNode.h"
#include "../../IR/basicBlock/ProgrameStructure.h"

namespace AST 
{
	class FunctionDeclaration;
	class SequenceInstruction;
	
    class ProgramNode : public AbstractNode
    {
    public:
    
		/**
		 * @brief ProgramNode constructor
		 * @param liextBefore a shared_ptr to the list of extern instructions written before the main
		 * @param main a shared_ptr to the definition of the main
		 * @param liextAfter a shared_ptr to the list of extern instructions written after the main
		 */
        ProgramNode(std::shared_ptr<SequenceInstruction> liextBefore, std::shared_ptr<FunctionDeclaration> main, std::shared_ptr<SequenceInstruction> liextAfter);
		
		 /**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
        
        /**
         * @brief deprecated function
         * @return an Error, value = 0, Value object.
         */
        virtual Value evaluate() const;

		/**
		* @brief buildIR build the IR from this node, that is the whole program IR
		* @return a shared pointer on the IR program structure that will contain the program IR to be built
		*/
        IR::sh_ProgrameStructure buildIR();

    private:
        std::shared_ptr<SequenceInstruction> liextBefore;
        std::shared_ptr<SequenceInstruction> liextAfter;
        std::shared_ptr<FunctionDeclaration> main;
    };
}


#endif // PROGRAM_NODE_H
