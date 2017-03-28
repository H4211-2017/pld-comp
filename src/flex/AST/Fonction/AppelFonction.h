#ifndef APPEL_FONCTION_H
#define APPEL_FONCTION_H
#include "Fonction.h"
#include "LParametres.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class AppelFonction : public AbstractExpression 
{
	
public:

    AppelFonction(std::string id,  std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope);
	
	virtual ~AppelFonction();

	virtual Value evaluate() const;

	// TODO : create class CFG and replace comment below.
	virtual void buildIR(/*std::shared_ptr<CFG>*/) const;
	
	void printTree(int tabulationNumber) const;

protected:
    
    std::shared_ptr<Fonction> fct;
    std::shared_ptr<LParametres> parametres;

};

} /* namespace AST */

#endif //ID_EXPRESSION_H
