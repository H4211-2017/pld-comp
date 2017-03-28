#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include "IDExpression.h"

#include "Variable/Variable.h"
#include "Scope.h"
#include "AbstractExpression.h"

namespace AST {

	class ArrayExpression : public IDExpression 
	{
		
	public:

		ArrayExpression(std::string id, std::shared_ptr<AbstractExpression> caseExpression,
				std::shared_ptr<Scope> scope);
		
		virtual ~ArrayExpression();

		virtual Value evaluate() const;

		// TODO : create class CFG and replace comment below.
		virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
		
		void printTree(int tabulationNumber) const;

	protected:
		
		std::shared_ptr<AbstractExpression> caseExpression;

	};
} /* namespace AST */

#endif //ARRAYEXPRESSION_H
