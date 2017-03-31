#include "Array.h"

#include <sstream>
#include <iostream>

using namespace AST;

Array::Array(std::shared_ptr<VariableSignature> signature, long int size)
	: AbstractVariable("Array", signature, false), size(size)
{
	
}
        
void Array::printTree(int tabulationNumber) const
{
	AbstractVariable::printTree(tabulationNumber);
	std::cout << "[" << size << "]" << std::endl;
}

Value Array::evaluate() const
{
	return Value();
}

void Array::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}
