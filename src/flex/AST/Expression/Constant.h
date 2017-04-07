#ifndef AST_CONSTANT_H
#define AST_CONSTANT_H

#include "AbstractExpression.h"

#include <memory>

namespace AST
{
    class Constant : public AbstractExpression
    {
		
    public:

        /**
         * @brief Constant constructor
         * @param value long int the value of the constant
         */
        Constant(long int value);
        
        /**
         * @brief Constant constructor
         * @param value char the value of the constant
         */
        Constant(char value);
        
        /**
         * @brief Constant destructor
         */
        virtual ~Constant();

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

		 /**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
    };

}
#endif // AST_CONSTANT_H
