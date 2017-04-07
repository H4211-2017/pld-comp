#ifndef COMPOSEDINSTRUCTION_H
#define COMPOSEDINSTRUCTION_H

#include "AbstractInstruction.h"

#include <vector>

#include "AbstractExpression.h"

namespace AST 
{
    class ComposedInstruction : public AbstractInstruction
    {
    
    public:
		
		/**
		 * @brief ComposedInstruction default constructor, with an empty list of expression
		 */
    	ComposedInstruction();
    	
    	/**
		 * @brief ComposedInstruction constructor, with an empty list of instructions
		 * @param name string the type of the node
		 */
    	ComposedInstruction(std::string name);
    	
        /**
         * @brief ComposedInstruction
         * @param abstractExpression a shared pointer to the first abstract expression of a composed instruction
         */
        ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression);

        /**
         * @brief addExpression add an expressionto the list of expressions of the instance
         * @param expression a shared_pointer to the expression to add
         */
        void addExpression(std::shared_ptr<AbstractExpression> expression);
        
        /**
         * @brief returns the list of Expression contained in the composed instruction 
         * @return a vector of shared_ptr to expressions which compose the instance
         */
        std::vector<std::shared_ptr<AbstractExpression>> getListExpr() const;

		/**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
        
        /**
         * @brief evaluate the Value of this node
         * @return the value of the last expression of the instance, if evaluable, or error null value otherwise
         */
        virtual Value evaluate() const;
        
        /**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the last expression's value once executed
		*/
       virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;  
        
    private:
    
        std::vector<std::shared_ptr<AbstractExpression>> listExpressions;
    };
}

#endif // COMPOSEDINSTRUCTION_H
