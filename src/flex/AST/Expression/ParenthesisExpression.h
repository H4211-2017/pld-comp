#ifndef PARENTHESIS_EXPRESSION_H
#define PARENTHESIS_EXPRESSION_H

#include "Instruction/AbstractInstruction.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class ParenthesisExpression : public AbstractExpression 
{
	
public:

    ParenthesisExpression(std::shared_ptr<AbstractInstruction> instr);
	
	virtual ~ParenthesisExpression();

	virtual Value evaluate() const;

	// TODO : create class CFG and replace comment below.
	virtual void buildIR(/*std::shared_ptr<CFG>*/) const;
	
	void printTree(int tabulationNumber) const;

protected:
    
    std::shared_ptr<AbstractInstruction> instr;

};

} /* namespace AST */

#endif //PARENTHESIS_EXPRESSION_H
