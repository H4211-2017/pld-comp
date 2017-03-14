#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include <memory>
#include "ExprNode.h"

class BinaryOperatorNode : public ExprNode
{
public:
	BinaryOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~BinaryOperatorNode();

protected:
	std::shared_ptr<ExprNode> m_pLeftExprNode;
	std::shared_ptr<ExprNode> m_pRightExprNode;
};

class PlusOperatorNode : public BinaryOperatorNode
{
public:
	PlusOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~PlusOperatorNode();
	
	virtual shared_ptr<long> evaluate() const;
}

class MinusOperatorNode : public BinaryOperatorNode
{
public:
	MinusOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~MinusOperatorNode();
	
	virtual shared_ptr<long> evaluate() const;
}

class MultOperatorNode : public MultOperatorNode
{
public:
	MultOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~MultOperatorNode();
	
	virtual shared_ptr<long> evaluate() const;
}

#endif // BINARYOPERATORNODE_H
