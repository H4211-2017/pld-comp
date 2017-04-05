#ifndef MULTEXPRESSION_H
#define MULTEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class MultExpression : public AbstractBinaryExpression
{

public:

	/**
	 * @brief MultExpression constructor
	 * @param leftMember a shared_ptr on the left part of the expression
	 * @param rightMember a shared_ptr on the right part of the expression
	 */
    MultExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

	/**
     * @brief MultExpression destructor
     */
    virtual ~MultExpression();
	
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

protected:
	/**
     * @brief printOperator Prints the operator of the binary expression. Used in printTree
     */
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //MULTEXPRESSION_H
