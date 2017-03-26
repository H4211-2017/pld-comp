#ifndef AFFECTATION_EXPRESSION_H
#define AFFECTATION_EXPRESSION_H

#include <memory>
#include "AbstractExpression.h"
#include <string>

namespace AST {

	enum OPAffect {
		AFFECT,
		AFFECT_MULT,
		AFFECT_DIV,
		AFFECT_ADD,
		AFFECT_SUB,
		AFFECT_MOD,
		AFFECT_BIT_AND,
		AFFECT_BIT_OR,
		AFFECT_BIT_XOR,
		AFFECT_BIT_LEFT_SHIFT,
		AFFECT_BIT_RIGHT_SHIFT
	};
	typedef enum OPAffect OPAffect;
}

namespace AST{
	
    class AffectationExpression : public AbstractExpression
    {
    public:
        AffectationExpression();
        AffectationExpression(std::string id, enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope);
        virtual ~AffectationExpression();

        virtual Value evaluate() const;
        /**
         * return a shared pointer to the value instancited by new if evaluable
         * or empty shared pointer else
         */

        virtual void buildIR() const;

        virtual void printTree(int tabulationNumber) const;
        
    protected :
    	std::string idVar;
		std::shared_ptr<AbstractExpression> transformedExpr;
    };

}

#endif
