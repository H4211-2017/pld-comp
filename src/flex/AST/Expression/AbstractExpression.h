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

        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
	};
}


std::shared_ptr<AST::AbstractExpression> make_shared_expr(AST::AbstractExpression* ptr);


#endif // ABSTRACTEXPRESSION_H
