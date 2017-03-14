#ifndef UNARYOPERATORNODE_H
#define UNARYOPERATORNODE_H

#include <memory>
#include "Expr.h"

class UnaryOperatorNode : public Expr
{
public:
	UnaryOperatorNode(std::shared_ptr<Expr> pDaughterExpr);

	virtual ~UnaryOperatorNode();

protected:
	std::shared_ptr<Expr> m_pDaughterExpr;
};

#endif // UNARYOPERATORNODE_H
