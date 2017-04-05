#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include "AbstractNode.h"


namespace AST
{
    
    class AbstractExpression : public AbstractNode
    {
		
	public:
		/**
         * @brief AbstractExpression constructor
         * @param name the type of the node (used by printTree)
         */
		AbstractExpression(std::string name);
		
		/**
         * @brief AbstractNode constructor
         * @param name the type of the node (used by printTree)
         * @param value the node's evaluation Value object
         */
		AbstractExpression(std::string name, Value value);
		
		/**
         * @brief AbstractNode constructor
         * @param name the type of the node (used by printTree)
         * @param type the type of the node's evaluation Value
         */
        AbstractExpression(std::string name, Type type);
        
        /**
         * @brief AbstractNode constructor
         * @param name the type of the node (used by printTree)
         * @param type the type of the node's evaluation Value
         * @param value the value of the node's evaluation Value
         */
		AbstractExpression(std::string name, Type type, long int value);
		
	};

}

/**
 * @brief Dynamically turn a polymorphed pointer on AbstractExpression into a shared_pointer
 * @param ptr AST::AbstractExpression* a polymorphed pointer on a subclass of AbstractExpression
 * @return a shared pointer
 */
std::shared_ptr<AST::AbstractExpression> make_shared_expr(AST::AbstractExpression* ptr);


#endif // ABSTRACTEXPRESSION_H
