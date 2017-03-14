#include "ExprNode.h"

ExprNode::ExprNode()
{
	
}

ExprNode::~ExprNode()
{
	
}

shared_ptr<ExprNode> ExprNode::reduce()
{
	shared_ptr<ExprNode> pReducedExprNode(this);
	
	shared_ptr<long> pEval = this->evaluate();
	
	if (pEval.use_count() != 0)
	{
		pReducedExprNode.reset(new Number(*pEval));
	}
	
	return pReducedExprNode;
}
