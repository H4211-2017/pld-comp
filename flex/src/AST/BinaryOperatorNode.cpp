#include "BinaryOperatorNode.h"
#include "Number.h"

using namespace std;

BinaryOperatorNode::BinaryOperatorNode(shared_ptr<ExprNode> pLeftExprNode,
		shared_ptr<ExprNode> pRightExprNode) : ExprNode(), m_pLeftExprNode(pLeftExprNode), m_pRightExprNode(pRightExprNode);
{

}

BinaryOperatorNode::~BinaryOperatorNode();
{
	
}

AddOperatorNode::AddOperatorNode(shared_ptr<ExprNode> pLeftExprNode,
		shared_ptr<ExprNode> pRightExprNode) : BinaryOperatorNode(pLeftExprNode, pRightExprNode);
{

}

shared_ptr<long> AddOperatorNode::evaluate() const
{
	shared_ptr<long> pEval;
	
	shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
	shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
		pEval.reset(new long((*pLeftExprNodeEval) + (*pRightExprNodeEval)))
	}
	
	return pEval;
}

SubOperatorNode::SubOperatorNode(shared_ptr<ExprNode> pLeftExprNode,
		shared_ptr<ExprNode> pRightExprNode) : BinaryOperatorNode(pLeftExprNode, pRightExprNode);
{

}

shared_ptr<long> SubOperatorNode::evaluate() const
{
	shared_ptr<long> pEval;
	
	shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
	shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
		pEval.reset(new long((*pLeftExprNodeEval) - (*pRightExprNodeEval)))
	}
	
	return pEval;
}

MultOperatorNode::MultOperatorNode(shared_ptr<ExprNode> pLeftExprNode,
		shared_ptr<ExprNode> pRightExprNode) : BinaryOperatorNode(pLeftExprNode, pRightExprNode);
{

}

shared_ptr<long> MultOperatorNode::evaluate() const
{
	shared_ptr<long> pEval;
	
	shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
	shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
		pEval.reset(new long((*pLeftExprNodeEval) * (*pRightExprNodeEval)))
	}
	
	return pEval;
}

DivOperatorNode::DivOperatorNode(shared_ptr<ExprNode> pLeftExprNode,
		shared_ptr<ExprNode> pRightExprNode) : BinaryOperatorNode(pLeftExprNode, pRightExprNode);
{

}

shared_ptr<long> DivOperatorNode::evaluate() const
{
	shared_ptr<long> pEval;
	
	shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
	shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
		pEval.reset(new long((*pLeftExprNodeEval) / (*pRightExprNodeEval)))
	}
	
	return pEval;
}
