#ifndef TERNARY_H
#define TERNARY_H

#include "AbstractExpression.h"

#include "Instruction/ComposedInstruction.h"
#include "Structure/IfStructure.h"

namespace AST
{
    class Ternary : public AbstractExpression
    {
    
    public:
    	
        /**
         * @brief Ternary constructor
         * @param cond a shared_ptr on the expression to evaluate
         * @param truebranch a shared_ptr on the expression used if the cond == true
         * @param falsebranch a shared_par on the expression used if the cond == false
         */
        Ternary(std::shared_ptr<AbstractExpression> cond, std::shared_ptr<AbstractExpression> trueBranch, std::shared_ptr<AbstractExpression> falseBranch);

		 /**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
        
		/**
		 * @brief evaluate compute evaluation if possible beacuse of constants-composed expression
		 * @return the "Value" of the expression if evaluable, or error-type value else
		 */
        virtual Value evaluate() const;
        
		/**
		 * @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		 * @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		 * @return a shared pointer on the IR memory index that will contain the node's value once executed
		 * 		or nullptr if the node shouldn't be calculated to be a value
		 */	
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
    
		std::shared_ptr<IfStructure> equivalent;
    };
}

#endif // COMPOSEDINSTRUCTION_H

