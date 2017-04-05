#ifndef TERNARY_H
#define TERNARY_H

#include "Instruction/ComposedInstruction.h"
#include "AbstractExpression.h"
#include "Structure/IfStructure.h"

namespace AST {
    class Ternary : public AbstractExpression
    {
    public:
    
    	Ternary();
    	
        /**
         * @brief ComposedInstruction
         * @param abstractExpression the first abstract expression of a composed instruction
         */
        Ternary(std::shared_ptr<AbstractExpression> cond, std::shared_ptr<AbstractExpression> trueBranch, std::shared_ptr<AbstractExpression> falseBranch);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
		std::shared_ptr<IfStructure> equivalent;

    };
}


#endif // COMPOSEDINSTRUCTION_H

