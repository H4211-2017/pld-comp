/*
 * AbstractBinaryExpression.h
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#ifndef SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#define SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#include "AbstractExpression.h"


namespace AST{

class AbstractBinaryExpression : public AbstractExpression{
public:

	/**
	 * @brief AbstractBinaryExpression constructor
	 * @param name name of this node
	 * @param leftMember a shared_ptr on the left part of the expression
	 * @param rightMember a shared_ptr on the right part of the expression
	 */
    AbstractBinaryExpression(std::string name, std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);
    
    /**
     * @brief AbstractBinaryExpression destructor
     */
	virtual ~AbstractBinaryExpression();

    /**
     * @brief printTree Prints the structure of the expression
     * @param tabulationNumber the tabulation of this current node.
     */
    virtual void printTree(int tabulationNumber) const;

    /**
     * @brief evaluate pure virtual function
     * @return the "Value" of the expression, mainly it's type.
     */
    virtual Value evaluate() const =0;
    
    /**
    * @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
    * @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
    * 		that is currently being completed
    * @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
    * 		shouldn't be callable
    */
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const =0;
	
protected:
	 /**
     * @brief printOperator Prints the operator of the binary expression. Used in printTree
     */
    virtual void printOperator() const =0;

	std::shared_ptr<AbstractExpression> rightMember;
	std::shared_ptr<AbstractExpression> leftMember;
};
}
#endif /* SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_ */
