#ifndef APPEL_FONCTION_H
#define APPEL_FONCTION_H
#include "Function.h"
#include "LParametres.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class FunctionCall : public AbstractExpression
{
	
public:

    FunctionCall(std::string id,  std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope);
	
    virtual ~FunctionCall();

	virtual Value evaluate() const;

	virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
	
	void printTree(int tabulationNumber) const;


protected:
    std::string functionIdentifiant;
    std::shared_ptr<LParametres> parameters;

};

} /* namespace AST */

#endif //ID_EXPRESSION_H
