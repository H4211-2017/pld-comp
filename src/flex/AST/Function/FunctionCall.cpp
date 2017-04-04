#include "FunctionCall.h"

#include <algorithm>

#include "../../../IR/generator/Generator.h"

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

IR::sh_Memory FunctionCall::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	IR::Generator gen;
	std::list<IR::sh_AbstractData> irParams;
    std::vector<std::shared_ptr<AbstractExpression> > params = parametres->getParameters();

    for(int i = 0; i < params.size(); i++){
        std::shared_ptr<AbstractExpression> expr = params[i];
        irParams.push_front(expr->buildIR(currentBasicBlock));
    }

    IR::Type returnType = getValue().getIRType();
    IR::sh_Memory returnStatement = gen.getNewUnusedMemmory(returnType);
	// TODO : complete this function by using params
    std::list<IR::sh_AbsInstruction> absIntructions = gen.call(fct->getIrFunction(), irParams, returnStatement);
    currentBasicBlock->pushInstructionBack(absIntructions);
    return returnStatement;
}


