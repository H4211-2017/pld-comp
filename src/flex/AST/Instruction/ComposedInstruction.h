
#ifndef COMPOSEDINSTRUCTION_H
#define COMPOSEDINSTRUCTION_H

#include <vector>

#include "AbstractInstruction.h"
#include "AbstractExpression.h"

namespace AST {
    class ComposedInstruction : public AbstractInstruction
    {
    public:
		
		/**
		 * @brief ComposedInstruction constructor
		 */
    	ComposedInstruction();
    	
    	/**
		 * @brief ComposedInstruction constructor
		 * @param name string the type of the node
		 */
    	ComposedInstruction(std::string name);
    	
        /**
         * @brief ComposedInstruction
         * @param abstractExpression the first abstract expression of a composed instruction
         */
        ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression);

        /**
         * @brief addExpression
         * @param expression to add expressions to a composed instruction
         */
        void addExpression(std::shared_ptr<AbstractExpression> expression);
        
        /**
         * @brief returns the list of Expression contained in the composed instruction 
         * @return a vector of shared_ptr to expressions
         */
        std::vector<std::shared_ptr<AbstractExpression>> getListExpr() const;

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
        std::vector<std::shared_ptr<AbstractExpression>> listExpressions;

    };
}


#endif // COMPOSEDINSTRUCTION_H
