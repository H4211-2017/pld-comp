#ifndef ARRAY_H
#define ARRAY_H

#include "AbstractVariable.h"
#include "VariableSignature.h"

namespace AST
{
	class Array : public AbstractVariable
	{
	public:
        
        /**
         * @brief Array constructor
         * @param signature a shared_ptr to the array's VariableSignature
         * @param size long int the size of the array
         */
        Array(std::shared_ptr<VariableSignature> signature, long int size);
        
         /**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
        
        /**
		 * @brief evaluate the Value of the variable
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
        
    protected:
        long int size;    
    };
}

#endif // ARRAY_H
