#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H
#include "AbstractExpression.h"

#include "VariableScope.h"
namespace AST {

class IDExpression : public AbstractExpression 
{
	
public:

    IDExpression(std::string id,  std::shared_ptr<VariableScope> scope);
	
	virtual ~IDExpression();

	virtual Value evaluate() const;

	// TODO : create class CFG and replace comment below.
	virtual void buildIR(/*std::shared_ptr<CFG>*/) const;
	
	void printTree(int tabulationNumber) const;

protected:
    
    std::shared_ptr<AbstractExpression> val;

};

} /* namespace AST */

#endif //ID_EXPRESSION_H
