/*
 * UnaryExpression.h
 *
 *  Created on: Mar 23, 2017
 *      Author: jerome
 */

#ifndef SRC_FLEX_AST_UNARYEXPRESSION_H_
#define SRC_FLEX_AST_UNARYEXPRESSION_H_
#include "AbstractExpression.h"


namespace AST{

enum UnaryOp
{
	UMINUS,
	UPLUS,
	UBITN,
	UBOOLN
};

class UnaryExpression : public AbstractExpression{
public:

	/**
	 * @brief UnaryExpression constructor
	 * @param expr a shared_ptr to the affected expression
	 * @param op AST::UnaryOp the effective operator
	 */
    UnaryExpression(std::shared_ptr<AbstractExpression> expr, enum UnaryOp op);
    
    /**
     * @brief UnaryExpression destructor
     */
	virtual ~UnaryExpression();
	
	/**
	 * @brief op attribute getter
	 * @return an AST::UnaryOp
	 */
	UnaryOp getOp() const;

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
    
	
protected:
	/**
     * @brief printOperator Prints the operator of the binary expression. Used in printTree
     */
	virtual void printOperator() const;
	
	std::shared_ptr<AbstractExpression> expr;
	enum UnaryOp op;
};
}
#endif /* SRC_FLEX_AST_UNARYEXPRESSION_H_ */
