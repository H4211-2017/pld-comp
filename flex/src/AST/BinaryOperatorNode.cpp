#include "BinaryOperatorNode.h"

using namespace std;

BinaryOperatorNode::BinaryOperatorNode(shared_ptr<Expr> pLeftExpr,
		shared_ptr<Expr> pRightExpr) : Expr(), m_pLeftExpr(pLeftExpr), m_pRightExpr(pRightExpr);
{

}

BinaryOperatorNode::~BinaryOperatorNode();
{
	
}

PlusOperatorNode::PlusOperatorNode(shared_ptr<Expr> pLeftExpr,
		shared_ptr<Expr> pRightExpr) : BinaryOperatorNode(pLeftExpr, pRightExpr);
{

}
