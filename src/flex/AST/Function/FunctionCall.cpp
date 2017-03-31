#include "FunctionCall.h"

#include <algorithm>

using namespace AST;

FunctionCall::FunctionCall(std::string id,  std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope)
    : AbstractExpression("FunctionCall")
{
    fct = scope->findFunction(id);
	parametres = params;
	
	if(!fct->checkParametres(parametres))
	{
		std::cerr << "ERROR : parameters number does not match. " << std::endl;
		exit(-1);
	}
	
	this->setType(fct->getValue().getValue().first);
}


FunctionCall::~FunctionCall() {
	// TODO Auto-generated destructor stub
}

Value FunctionCall::evaluate() const
{
	return Value();
}

void FunctionCall::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    parametres->printTree(tabulationNumber + 1);
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory FunctionCall::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	
	return nullptr;
}
