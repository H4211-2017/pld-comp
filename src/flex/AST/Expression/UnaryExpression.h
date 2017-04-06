#ifndef SRC_FLEX_AST_UNARYEXPRESSION_H
#define SRC_FLEX_AST_UNARYEXPRESSION_H
#include "AbstractExpression.h"

namespace AST
{
	enum UnaryOp
	{
		UMINUS,
		UPLUS,
		UBITN,
		UBOOLN
	};

	class UnaryExpression : public AbstractExpression
	{
	
	public:

		/**
		 * @brief UnaryExpression constructor
		 * @param expr a shared_ptr to the affected expression
		 * @param op AST::UnaryOp the effective operator
		 */
		UnaryExpression(std::shared_ptr<AbstractExpression> expr, enum UnaryOp op);
		
		/**
		 * @brief UnaryExpression destructor
		 */
		virtual ~UnaryExpression();
	
		/**
		 * @brief op attribute getter
		 * @return an AST::UnaryOp
		 */
		UnaryOp getOp() const;

		/**
		 * @brief printTree the AST tree corresponding to this node and it's children.
		 * @param tabulationNumber the number of tabulations corresponding to this node
		 */
		virtual void printTree(int tabulationNumber) const;
		
		/**
		 * @brief evaluate compute evaluation if possible beacuse of constants-composed expression
		 * @return the "Value" of the expression if evaluable, or error-type value else
		 */
		virtual Value evaluate() const;
		
		/**
		 * @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		 * @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		 * @return a shared pointer on the IR memory index that will contain the node's value once executed
		 * 		or nullptr if the node shouldn't be calculated to be a value
		 */	
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
	
	protected:
	
		/**
		 * @brief printOperator Prints the operator of the binary expression. Used in printTree
		 */
		virtual void printOperator() const;
	
		std::shared_ptr<AbstractExpression> expr;
		enum UnaryOp op;
	};
}
#endif // SRC_FLEX_AST_UNARYEXPRESSION_H
