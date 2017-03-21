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

class AddOperatorNode : public BinaryOperatorNode
{
public:
	AddOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~AddOperatorNode();
	
    virtual std::shared_ptr<long> evaluate() const;
};

class SubOperatorNode : public BinaryOperatorNode
{
public:
	SubOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~SubOperatorNode();
	
    virtual std::shared_ptr<long> evaluate() const;
};

class MultOperatorNode : public MultOperatorNode
{
public:
	MultOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~MultOperatorNode();
	
    virtual std::shared_ptr<long> evaluate() const;
};

class DivOperatorNode : public DivOperatorNode
{
public:
	DivOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~DivOperatorNode();
	
    virtual std::shared_ptr<long> evaluate() const;
};

class ModOperatorNode : public ModOperatorNode
{
public:
	ModOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode);

	virtual ~ModOperatorNode();
	
    virtual std::shared_ptr<long> evaluate() const;
};



#endif // BINARYOPERATORNODE_H
