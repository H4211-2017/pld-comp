#include "AppelFonction.h"

#include <algorithm>

using namespace AST;

AppelFonction::AppelFonction(std::string id,  std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope)
    : AbstractExpression("AppelFonction")
{
	fct = scope->findFonction(id);
	parametres = params;
	
	if(!fct->checkParametres(parametres))
	{
		std::cerr << "ERROR : parameters number does not match. " << std::endl;
		exit(-1);
	}
	
	this->setType(fct->getValue().getValue().first);
}


AppelFonction::~AppelFonction() {
	// TODO Auto-generated destructor stub
}

Value AppelFonction::evaluate() const
{
	return Value();
}

void AppelFonction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    parametres->printTree(tabulationNumber + 1);
}

// TODO : create class CFG and replace comment below.
void AppelFonction::buildIR(/*std::shared_ptr<BasicBlock>*/) const
{
	
}
