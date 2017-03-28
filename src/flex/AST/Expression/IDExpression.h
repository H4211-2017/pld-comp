#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H

#include "Variable/Variable.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class IDExpression : public AbstractExpression 
{
	
public:

    IDExpression(std::string id,  std::shared_ptr<Scope> scope);
    IDExpression(std::string name, std::string id,  std::shared_ptr<Scope> scope);
	
	virtual ~IDExpression();

	virtual Value evaluate() const;

	// TODO : create class CFG and replace comment below.
	virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
	
	void printTree(int tabulationNumber) const;

protected:
    
    std::shared_ptr<Variable> val;

};

} /* namespace AST */

#endif //ID_EXPRESSION_H
