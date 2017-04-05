#ifndef DECR_INCR_RIGHT_EXPRESSION_H
#define DECR_INCR_RIGHT_EXPRESSION_H

#include "AbstractExpression.h"
#include "Variable/Variable.h"

namespace AST {

class DecrIncrRightExpression : public AbstractExpression
{

public:

	/**
    * @brief DecrIncrRight constructor
    * @param valueOfIncrement int the value of incrementation
    * @remark value of incrementation +1 is an incrementation, value of incrementation -1 is a decrementation 
    */
    DecrIncrRightExpression(std::shared_ptr<AbstractVariable> var, int valueOfIncrement);

	/**
	 * @brief DecrIncrRight destructor
	 */
    virtual ~DecrIncrRightExpression();

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

private:
    std::shared_ptr<AbstractVariable> var;
    int valueOfIncrement;

};

} /* namespace AST */

#endif //DECR_INCR_RIGHT_EXPRESSION_H
