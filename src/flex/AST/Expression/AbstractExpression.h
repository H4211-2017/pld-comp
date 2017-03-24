#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include "AbstractNode.h"


namespace AST
{
    
	class AbstractExpression : public AbstractNode
	{
		
	public:
		AbstractExpression(std::string name);
		AbstractExpression(std::string name, Value value);
        AbstractExpression(std::string name, Type type);
		AbstractExpression(std::string name, Type type, long int value);
	};

}


std::shared_ptr<AST::AbstractExpression> make_shared_expr(AST::AbstractExpression* ptr);

struct ExprNode 
{
	ExprNode(std::shared_ptr<AST::AbstractExpression> n) : node(n)
	{
		
	}
	
	std::shared_ptr<AST::AbstractExpression> node;
};
typedef struct ExprNode ExprNode;

#endif // ABSTRACTEXPRESSION_H
