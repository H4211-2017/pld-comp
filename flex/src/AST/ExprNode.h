#ifndef EXPRNODE_H
#define EXPRNODE_H

#include "Node.h"

class ExprNode : public Node
{
public:
	ExprNode();
	
	virtual ~ExprNode();
	
	virtual shared_ptr<Expr> reduce() = 0;

private:

};

#endif // EXPRNODE_H
