#include "Array.h"

#include <sstream>
#include <iostream>

using namespace AST;

Array::Array(std::shared_ptr<VariableSignature> signature, long int size)
	: Variable("Array", signature, false), size(size)
{
	
}
        
void Array::printTree(int tabulationNumber) const
{
	Variable::printTree(tabulationNumber);
	std::cout << "[" << size << "]" << std::endl;
}

Value Array::evaluate() const
{
	return Value();
}

void Array::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}
