#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include <memory>
#include "Expr.h"

class BinaryOperatorNode : public Expr
{
public:
	BinaryOperatorNode(std::shared_ptr<Expr> pLeftExpr, std::shared_ptr<Expr> pRightExpr);

	virtual ~BinaryOperatorNode();

protected:
	std::shared_ptr<Expr> m_pLeftExpr;
	std::shared_ptr<Expr> m_pRightExpr;
};

class PlusOperatorNode : public BinaryOperatorNode
{
public:
	PlusOperatorNode(std::shared_ptr<Expr> pLeftExpr, std::shared_ptr<Expr> pRightExpr);

	virtual ~PlusOperatorNode();	
}

#endif // BINARYOPERATORNODE_H
