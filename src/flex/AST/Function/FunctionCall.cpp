#include "FunctionCall.h"

#include <algorithm>

#include "../../../IR/generator/Generator.h"
#include "../../../IR/function/ExternalFunction.h"

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
    IR::Generator gen;
	std::list<IR::sh_AbstractData> irParams;
    std::vector<std::shared_ptr<AbstractExpression> > params = parameters->getParameters();
    std::shared_ptr<Function> fct = currentScope->findFunction(functionIdentifiant);

    for(int i = 0; i < params.size(); i++){
        std::shared_ptr<AbstractExpression> expr = params[i];
        irParams.push_front(expr->buildIR(currentBasicBlock));
    }

    IR::Type returnType = getValue().getIRType();
    IR::sh_Memory returnStatement = gen.getNewUnusedMemmory(returnType);

    std::cout << "FunctionCall::buildIR : before build instructions" << std::endl;
    std::list<IR::sh_AbsInstruction> absInstructions;
    if (functionIdentifiant == "getchar")
    {
        std::shared_ptr<IR::ExternalFunction> getCharFunctionIR = std::make_shared<IR::ExternalFunction>("getchar", IR::Type::CHAR);
        absInstructions = gen.call(getCharFunctionIR, irParams, returnStatement);
    }
    else if (functionIdentifiant == "putchar")
    {
        std::cout << "FunctionCall::buildIR : in putchar" << std::endl;
        std::shared_ptr<IR::ExternalFunction> putCharFunctionIR = std::make_shared<IR::ExternalFunction>("putchar", IR::Type::VOID);
        std::cout << "FunctionCall::buildIR : after make_shared" << std::endl;
        putCharFunctionIR->pushBackNewParam(irParams.front());
        std::cout << "FunctionCall::buildIR : after pushBackNewParams" << std::endl;
        absInstructions = gen.call(putCharFunctionIR, irParams);
        std::cout << "FunctionCall::buildIR : after gen.call" << std::endl;
    }
    else
    {
        if (returnStatement->getType() == IR::Type::VOID)
        {
            absInstructions = gen.call(fct->getIrFunction(), irParams);
        }
        else
        {
            absInstructions = gen.call(fct->getIrFunction(), irParams, returnStatement);
        }

    }
    currentBasicBlock->pushInstructionBack(absInstructions);
    return returnStatement;
}


