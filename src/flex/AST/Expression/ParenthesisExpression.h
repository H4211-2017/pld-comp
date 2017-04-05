#ifndef PARENTHESIS_EXPRESSION_H
#define PARENTHESIS_EXPRESSION_H

#include "Instruction/AbstractInstruction.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class ParenthesisExpression : public AbstractExpression 
{
	
public:

	/**
	 * @brief ParenthesisExpression constructor
	 * @param instr a shared_ptr on the contained instruction
	 */
    ParenthesisExpression(std::shared_ptr<AbstractInstruction> instr);
	
	/**
	 * @brief ParenthesisExpression destructor
	 */
	virtual ~ParenthesisExpression();

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
	void printTree(int tabulationNumber) const;

protected:
    
    std::shared_ptr<AbstractInstruction> instr;

};

} /* namespace AST */

#endif //PARENTHESIS_EXPRESSION_H
