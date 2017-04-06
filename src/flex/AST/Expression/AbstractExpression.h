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
         * @remark the value is setted to 0
         */
        AbstractExpression(std::string name, Type type);
        
        /**
         * @brief AbstractNode constructor
         * @param name the type of the node (used by printTree)
         * @param type the type of the node's evaluation Value
         * @param value the value of the node's evaluation Value
         */
		AbstractExpression(std::string name, Type type, long int value);
		
	   /**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once executed
		* 		or nullptr if the node shouldn't be calculated to be a value
		*/
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
		
	};

}

/**
 * @brief Dynamically turn a polymorphed pointer on AbstractExpression into a shared_pointer
 * 			(useful for bison that doesn't manage shared pointer polymorphism)
 * @param ptr AST::AbstractExpression* a polymorphed pointer to a subclass of AbstractExpression
 * @return a shared pointer to an AbstractExpression
 */
std::shared_ptr<AST::AbstractExpression> make_shared_expr(AST::AbstractExpression* ptr);


#endif // ABSTRACTEXPRESSION_H
