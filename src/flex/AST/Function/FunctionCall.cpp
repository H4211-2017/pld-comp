#include "FunctionCall.h"

#include <algorithm>

#include "../../../IR/generator/Generator.h"

using namespace AST;

FunctionCall::FunctionCall(std::string id,  std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope)
    : AbstractExpression("FunctionCall", scope), parameters(params), functionIdentifiant(id)
{
    std::shared_ptr<Function> fct = scope->findFunction(id); // check if function exists in scope (at least declared)
	
    if(!fct->checkParametres(parameters))
	{
		std::cerr << "ERROR : parameters number does not match. " << std::endl;
		exit(-1);
	}
	
	this->setType(fct->getValue().getValue().first);
}


FunctionCall::~FunctionCall() {
}

Value FunctionCall::evaluate() const
{
	return Value();
}

void FunctionCall::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    parameters->printTree(tabulationNumber + 1);
}

IR::sh_Memory FunctionCall::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    std::cout << "FunctionCall::buildIR : begin" << std::endl;
    std::cout << "FunctionCall::buildIR : currentScope : " << currentScope << std::endl;
    std::cout << "FunctionCall::buildIR : parameters : " << parameters << std::endl;
    std::cout << "FunctionCall::buildIR : functionIdentifiant : " << functionIdentifiant << std::endl;
    IR::Generator gen;
	std::list<IR::sh_AbstractData> irParams;
    std::vector<std::shared_ptr<AbstractExpression> > params = parameters->getParameters();
    std::cout << "FunctionCall::buildIR : before findFunction" << std:: endl;
    std::shared_ptr<Function> fct = currentScope->findFunction(functionIdentifiant);

    std::cout << "FunctionCall::buildIR : before params loop" << std::endl;
    for(int i = 0; i < params.size(); i++){
        std::shared_ptr<AbstractExpression> expr = params[i];
        irParams.push_front(expr->buildIR(currentBasicBlock));
    }
    std::cout << "FunctionCall::buildIR : after params loop" << std::endl;

    IR::Type returnType = getValue().getIRType();
    IR::sh_Memory returnStatement = gen.getNewUnusedMemmory(returnType);
	// TODO : complete this function by using params

    std::list<IR::sh_AbsInstruction> absIntructions = gen.call(fct->getIrFunction(), irParams, returnStatement);
    currentBasicBlock->pushInstructionBack(absIntructions);
    std::cout << "FunctionCall::buildIR : end" << std::endl;
    return returnStatement;
}


