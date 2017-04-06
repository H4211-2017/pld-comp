#ifndef AFFECTATION_EXPRESSION_H
#define AFFECTATION_EXPRESSION_H

#include "AbstractExpression.h"

#include <memory>
#include <string>

#include "Variable/Variable.h"

namespace AST 
{
	enum OPAffect
	{
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
	
    class AffectationExpression : public AbstractExpression
    {
    public:
		
		 /**
		 * @brief AffectationExpression constructor
		 */
        AffectationExpression();
        
        /**
		 * @brief AffectationExpression constructor
		 * @param id the id of the variable that is the left part of the affectation
		 * @param op AST::OPAffect indicating the type of affectation
		 * @param rightMember a shared_ptr on the right part of the expression
		 * @param scope a shared_ptr on the current Scope
		 */
        AffectationExpression(std::string id, enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope);
        
        /**
		 * @brief AffectationExpression constructor
		 * @param variable a shared_ptr of the Variable that is the left part of the affectation
		 * @param op AST::OPAffect indicating the type of affectation
		 * @param rightMember a shared_ptr on the right part of the expression
		 * @param scope a shared_ptr on the current Scope
		 */
        AffectationExpression(std::shared_ptr<Variable> variable, enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope);
        
        /**
		* @brief AffectationExpression destructor
		*/
        virtual ~AffectationExpression();
        
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

		 /**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
        
    protected :
    	std::shared_ptr<AbstractVariable> var;
		std::shared_ptr<AbstractExpression> transformedExpr;
		
		/**
		 * @brief contains the switch used in the constructor
		 */
		void switchOperatorMake(enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope);
    };

}

#endif
