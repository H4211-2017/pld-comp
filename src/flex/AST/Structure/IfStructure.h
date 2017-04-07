#ifndef IFSTRUCTURE_H
#define IFSTRUCTURE_H

#include "AbstractStructure.h"

#include "Instruction/AbstractInstruction.h"
#include "Instruction/ComposedInstruction.h"
#include "Structure/ElseStructure.h"

namespace AST
{
	class IfStructure : public AbstractStructure
	{
		
	public:
        /**
         * @brief IfStructure
         * @param condition instruction that is the condition of this structure
         * @param intInstruction the interior instruction inside the if condition is true
         * @param elseStructure the structure of code used if condition false
         */
		IfStructure(std::shared_ptr<ComposedInstruction> condition,
				std::shared_ptr<AbstractInstruction> intInstruction, 
				std::shared_ptr<ElseStructure> elseStructure);
				

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
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

	private:
		std::shared_ptr<ComposedInstruction> condition;
		std::shared_ptr<AbstractInstruction> intInstruction;
		std::shared_ptr<ElseStructure> elseStructure;
	};
}

#endif // IFSTRUCTURE_H
