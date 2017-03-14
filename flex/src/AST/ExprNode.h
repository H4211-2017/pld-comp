#ifndef EXPRNODE_H
#define EXPRNODE_H

#include "Node.h"

class ExprNode : public Node
{
public:
	ExprNode();
	
	virtual ~ExprNode();
	
	shared_ptr<ExprNode> reduce();
	/**
	 * not const because can return this, can reduce expr if only composed
	 * of constants, else return this.
	 */

private:

};

#endif // EXPRNODE_H
