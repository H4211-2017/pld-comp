#include "Variable.h"

#include <sstream>
#include <iostream>

using namespace AST;

Variable::Variable(std::shared_ptr<VariableSignature> signature, bool decl, const IR::Generator &generator)
	: AbstractVariable("Variable", signature, decl)
{
	IR::Type irType = signature->getValue().getIRType();
	memory = generator.getNewUnusedMemmory(irType);
}

Value Variable::evaluate() const
{
	return Value();
}

IR::sh_Memory Variable::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	return memory;
}
