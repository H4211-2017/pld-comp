#ifndef ELSESTRUCTURE_H
#define ELSESTRUCTURE_H

#include "AbstractNode.h"

#include "Instruction/AbstractInstruction.h"

namespace AST
{
	class ElseStructure : public AbstractNode
	{
		
	public:
		ElseStructure();
		ElseStructure(std::shared_ptr<AbstractInstruction> intInstruction);
		ElseStructure(Value value, std::shared_ptr<AbstractInstruction> intInstruction);
		ElseStructure(Type type, long int value, std::shared_ptr<AbstractInstruction> intInstruction);
						
		virtual Value evaluate() const;

        virtual void printTree(int tabulationNumber) const;

		virtual void buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const;
		
	private:
		std::shared_ptr<AbstractInstruction> intInstruction;
	};
}

#endif // ELSESTRUCTURE_H