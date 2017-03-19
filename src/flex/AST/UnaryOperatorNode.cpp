#include "UnaryOperatorNode.h"

UnaryOperatorNode::UnaryOperatorNode(std::shared_ptr<ExprNode> pDaughterExprNode)
		: ExprNode(), m_pDaughterExprNode(pDaughterExprNode);
{

}

UnaryOperatorNode::~UnaryOperatorNode();
{
	
}
