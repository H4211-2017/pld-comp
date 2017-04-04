#include "ArrayDeclaration.h"

#include "VariableSignature.h"
#include "Array.h"
#include "Scope.h"

#include <cstring>

using namespace AST;

/****************AVEC TAILLE********************************/

ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
		long int size, std::shared_ptr<Scope> scope)
	: AbstractInstruction("ArrayDeclaration")
{	
	array = std::make_shared<Array>(signature, size);
	scope->declareVariable(signature->getIdentifiant(), array);
	eventualInit = NULL;
}

ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, char* valeurs, std::shared_ptr<Scope> scope)
	: AbstractInstruction("ArrayDeclaration")
	
{
	array = std::make_shared<Array>(signature, size + 1);
	scope->declareVariable(signature->getIdentifiant(), array);
	eventualInit = valeurs;
	eventualInit[size] = '\0';
}

ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<ComposedInstruction> valeurs, std::shared_ptr<Scope> scope)
	: AbstractInstruction("ArrayDeclaration")
{
	array = std::make_shared<Array>(signature, size);
	scope->declareVariable(signature->getIdentifiant(), array);
	
	std::vector<std::shared_ptr<AbstractExpression>>  valOfTab = valeurs->getListExpr();
	
	for(int i=0; i<size && i<valOfTab.size(); i++)
	{
		eventualTabInit.push_back(valOfTab[i]);
	}
	
	eventualInit = NULL;
	
}			

/*******************SANS TAILLE****************************/

ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature,
						char* valeurs, std::shared_ptr<Scope> scope)
	: AbstractInstruction("ArrayDeclaration")
{
	array = std::make_shared<Array>(signature, strlen(valeurs) + 1);
	scope->declareVariable(signature->getIdentifiant(), array);
	eventualInit = valeurs;
	eventualInit[strlen(valeurs)] = '\0';
}


ArrayDeclaration::ArrayDeclaration(std::shared_ptr<VariableSignature> signature,
				std::shared_ptr<ComposedInstruction> valeurs, std::shared_ptr<Scope> scope)
	: AbstractInstruction("ArrayDeclaration")
{
	std::vector<std::shared_ptr<AbstractExpression>>  valOfTab = valeurs->getListExpr();
	
	array = std::make_shared<Array>(signature, valOfTab.size());
	scope->declareVariable(signature->getIdentifiant(), array);
	
	for(int i=0;i<valOfTab.size(); i++)
	{
		eventualTabInit.push_back(valOfTab[i]);
	}
	
	eventualInit = NULL;
	
}

void ArrayDeclaration::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    this->array->printTree(tabulationNumber + 1);
    if(eventualInit != NULL)
    {
		std::cout << std::endl;
		for(int i=0; i<=tabulationNumber; i++, std::cout << "  ");
		std::cout << "TAB VAL CHAIN : " << eventualInit;
	}
	else if(eventualTabInit.size() > 0)
	{
		std::cout << std::endl;
		for(int i=0; i<=tabulationNumber; i++, std::cout << "  ");
		
		std::cout << "TAB VALS : ";
		for(int i=0; i<eventualTabInit.size(); i++)
		{
			std::cout << std::endl;
			eventualTabInit[i]->printTree(tabulationNumber + 1);
		}
	}
}

Value ArrayDeclaration::evaluate() const
{
	return Value();
}

IR::sh_Memory ArrayDeclaration::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

	return nullptr;
}

