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
    UMINUS, // -
    UPLUS,  // +
    UBITN,  // ~
    UBOOLN  // !
};

typedef enum UnaryOp UnaryOp;

class UnaryExpression : public AbstractExpression{
public:
    UnaryExpression(std::shared_ptr<AbstractExpression> expr, enum UnaryOp op);
	virtual ~UnaryExpression();
	
	UnaryOp getOp() const;

    virtual void printTree(int tabulationNumber) const;
    virtual Value evaluate() const;
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
    
	
protected:
	virtual void printOperator() const;
	
	std::shared_ptr<AbstractExpression> expr;
	enum UnaryOp op;
};
}
#endif /* SRC_FLEX_AST_UNARYEXPRESSION_H_ */
