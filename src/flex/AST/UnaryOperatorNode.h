#ifndef UNARYOPERATORNODE_H
#define UNARYOPERATORNODE_H

#include <memory>
#include "ExprNode.h"

class UnaryOperatorNode : public ExprNode
{
public:
	UnaryOperatorNode(std::shared_ptr<ExprNode> pDaughterExprNode);

	virtual ~UnaryOperatorNode();

protected:
	std::shared_ptr<ExprNode> m_pDaughterExprNode;
};

#endif // UNARYOPERATORNODE_H
