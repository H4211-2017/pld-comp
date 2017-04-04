#ifndef ELSESTRUCTURE_H
#define ELSESTRUCTURE_H

#include "AbstractNode.h"

#include "Instruction/AbstractInstruction.h"

namespace AST
{
	class ElseStructure : public AbstractNode
	{
		
	public:
        /**
         * @brief ElseStructure default constructor, calls constructor of AbstractInstruction, with param ElseStructure.
         */
		ElseStructure();

        /**
         * @brief ElseStructure constructor
         * @param intInstruction the instructions in the else.
         */
		ElseStructure(std::shared_ptr<AbstractInstruction> intInstruction);

        /**
         * @brief evaluate the Value of this node
         * @return a Value of Type error that = 0
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
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
		
	private:
		std::shared_ptr<AbstractInstruction> intInstruction;
	};
}

#endif // ELSESTRUCTURE_H
