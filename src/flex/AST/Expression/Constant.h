#ifndef AST_CONSTANT_H
#define AST_CONSTANT_H

#include <memory>
#include "AbstractExpression.h"

namespace AST{
	
    class Constant : public AbstractExpression
    {
    public:
		/**
         * @brief Constant constructor
         */
        Constant();
        
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

		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
    };

}
#endif // AST_CONSTANT_H
