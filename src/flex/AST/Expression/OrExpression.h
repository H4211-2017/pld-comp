#ifndef OREXPRESSION_H
#define OREXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST
{
	class OrExpression : public AbstractBinaryExpression
	{

	public:

		OrExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

		virtual ~OrExpression();

		virtual Value evaluate() const;
		
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

	protected:
	
		virtual void printOperator() const;
	};
} /* namespace AST */

#endif //OREXPRESSION_H
