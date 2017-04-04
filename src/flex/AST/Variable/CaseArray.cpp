#include "CaseArray.h"

#include <sstream>
#include <iostream>

using namespace AST;

CaseArray::CaseArray(std::shared_ptr<Array> array, std::shared_ptr<AbstractExpression> index)
	: Variable("CaseArray", array->getSignature(), false), array(array), index(index)
{
	
}

CaseArray::~CaseArray()
{

}
        
void CaseArray::printTree(int tabulationNumber) const
{
	AbstractNode::printTree(tabulationNumber);
	std::cout << array->getSignature()->getIdentifiant() << "[ EXPR UNDER ]" << std::endl;
	index->printTree(tabulationNumber + 1);
}

Value CaseArray::evaluate() const
{
	return Value();
}

IR::sh_Memory CaseArray::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    return nullptr;
}

