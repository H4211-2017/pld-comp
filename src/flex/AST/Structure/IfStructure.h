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
         * @brief buildIR builds the blocs corresponding to this bloc, and it's children.
         */
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

	private:
		std::shared_ptr<ComposedInstruction> condition;
		std::shared_ptr<AbstractInstruction> intInstruction;
		std::shared_ptr<ElseStructure> elseStructure;
	};
}

#endif // IFSTRUCTURE_H
