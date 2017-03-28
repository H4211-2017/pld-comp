#ifndef IFSTRUCTURE_H
#define IFSTRUCTURE_H

#include "AbstractStructure.h"

#include "Instruction/AbstractInstruction.h"
#include "Instruction/ComposedInstruction.h"
#include "ElseStructure.h"

namespace AST
{
	class IfStructure : public AbstractStructure
	{
		
	public:
		IfStructure(std::shared_ptr<ComposedInstruction> condition,
				std::shared_ptr<AbstractInstruction> intInstruction, 
				std::shared_ptr<ElseStructure> elseStructure);
		IfStructure(Value value, std::shared_ptr<ComposedInstruction> condtion,
				std::shared_ptr<AbstractInstruction> intInstruction, 
				std::shared_ptr<ElseStructure> elseStructure);
		IfStructure(Type type, long int value,
				std::shared_ptr<ComposedInstruction> condtion,
				std::shared_ptr<AbstractInstruction> intInstruction, 
				std::shared_ptr<ElseStructure> elseStructure);
				
		virtual Value evaluate() const;

        virtual void printTree(int tabulationNumber) const;

		virtual void buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const;
		
	private:
		std::shared_ptr<ComposedInstruction> condition;
		std::shared_ptr<AbstractInstruction> intInstruction;
		std::shared_ptr<ElseStructure> elseStructure;
	};
}

#endif // IFSTRUCTURE_H
