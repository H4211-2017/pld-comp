#include "UnaryOperatorNode.h"

UnaryOperatorNode::UnaryOperatorNode(std::shared_ptr<Expr> pDaughterExpr)
		: Expr(), m_pDaughterExpr(pDaughterExpr);
{

}

UnaryOperatorNode::~UnaryOperatorNode();
{
	
}
