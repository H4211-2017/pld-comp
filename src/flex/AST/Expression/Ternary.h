#ifndef TERNARY_H
#define TERNARY_H

#include "Instruction/ComposedInstruction.h"
#include "AbstractExpression.h"
#include "Structure/IfStructure.h"

namespace AST {
    class Ternary : public AbstractExpression
    {
    public:
		
		/**
		 * @brief Ternary constructor
		 */
    	Ternary();
    	
        /**
         * @brief Ternary constructor
         * @param cond a shared_ptr on the expression to evaluate
         * @param truebranch a shared_ptr on the expression used if the cond == true
         * @param falsebranch a shared_par on the expression used if the cond == false
         */
        Ternary(std::shared_ptr<AbstractExpression> cond, std::shared_ptr<AbstractExpression> trueBranch, std::shared_ptr<AbstractExpression> falseBranch);

		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
        
        /**
		 * @brief evaluate pure virtual function
		 * @return the "Value" of the expression, mainly it's type.
		 */
        virtual Value evaluate() const;
        
        /**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    private:
		std::shared_ptr<IfStructure> equivalent;

    };
}


#endif // COMPOSEDINSTRUCTION_H

