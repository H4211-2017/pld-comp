#ifndef CASE_ARRAY_H
#define CASE_ARRAY_H

#include "Variable.h"
#include "Array.h"
#include "AbstractExpression.h"

namespace AST
{
	class CaseArray : public Variable
	{
	public:
        
        /**
         * @brief CaseArray constructor
         * @param array a shared_ptr to the Array the instance belongs to
         * @param index a shared_ptr to the expression that will be evaluated as the index of the CaseArray
         */
        CaseArray(std::shared_ptr<Array> array, std::shared_ptr<AbstractExpression> index);
        
        /**
         * @brief CaseArray destructor
         */
        virtual ~CaseArray();
        
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
        std::shared_ptr<AbstractExpression> index;
        std::shared_ptr<Array> array;
    };
}

#endif // CASE_ARRAY_H

