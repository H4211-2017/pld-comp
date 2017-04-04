#ifndef TERNARY_H
#define TERNARY_H

#include "ComposedInstruction.h"
#include "Expression/AbstractExpression.h"
#include "Structure/IfStructure.h"

namespace AST {
    class Ternary : public ComposedInstruction
    {
    public:
    
    	Ternary();
    	
        /**
         * @brief ComposedInstruction
         * @param abstractExpression the first abstract expression of a composed instruction
         */
        Ternary(std::shared_ptr<AbstractExpression> cond, std::shared_ptr<ComposedInstruction> trueBranch, std::shared_ptr<ComposedInstruction> falseBranch);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
		std::shared_ptr<IfStructure> equivalent;

    };
}


#endif // COMPOSEDINSTRUCTION_H

