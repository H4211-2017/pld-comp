#include "BinaryOperatorNode.h"
//#include "Number.h"
#include <memory>


BinaryOperatorNode::BinaryOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode):
    ExprNode(), m_pLeftExprNode(pLeftExprNode), m_pRightExprNode(pRightExprNode)
{

}

BinaryOperatorNode::~BinaryOperatorNode()
{
	
}

AddOperatorNode::AddOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode):
    BinaryOperatorNode(pLeftExprNode, pRightExprNode)
{

}

std::shared_ptr<long> AddOperatorNode::evaluate() const
{
    std::shared_ptr<long> pEval;
	
    std::shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
    std::shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
        pEval.reset(new long((*pLeftExprNodeEval) + (*pRightExprNodeEval)));
	}
	
	return pEval;
}

SubOperatorNode::SubOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode):
    BinaryOperatorNode(pLeftExprNode, pRightExprNode)
{

}

std::shared_ptr<long> SubOperatorNode::evaluate() const
{
    std::shared_ptr<long> pEval;
	
    std::shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
    std::shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
        pEval.reset(new long((*pLeftExprNodeEval) - (*pRightExprNodeEval)));
	}
	
	return pEval;
}

MultOperatorNode::MultOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode):
    BinaryOperatorNode(pLeftExprNode, pRightExprNode)
{

}

std::shared_ptr<long> MultOperatorNode::evaluate() const
{
    std::shared_ptr<long> pEval;
	
    std::shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
    std::shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
        pEval.reset(new long((*pLeftExprNodeEval) * (*pRightExprNodeEval)));
	}
	
	return pEval;
}

DivOperatorNode::DivOperatorNode(std::shared_ptr<ExprNode> pLeftExprNode, std::shared_ptr<ExprNode> pRightExprNode):
    BinaryOperatorNode(pLeftExprNode, pRightExprNode)
{

}

std::shared_ptr<long> DivOperatorNode::evaluate() const
{
    std::shared_ptr<long> pEval;
	
    std::shared_ptr<long> pLeftExprNodeEval = pLeftExprNode->evaluate();
    std::shared_ptr<long> pRightExprNodeEval = pRightExprNode->evaluate();
	
	if (pLeftExprNodeEval.use_count() != 0 && pRightExprNodeEval.use_count() != 0)
	{
        pEval.reset(new long((*pLeftExprNodeEval) / (*pRightExprNodeEval)));
	}
	
	return pEval;
}
