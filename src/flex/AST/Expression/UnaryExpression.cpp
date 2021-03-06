#include "UnaryExpression.h"
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/UnaryOperator.h"

#include <iostream>

using namespace AST;

UnaryExpression::UnaryExpression(std::shared_ptr<AbstractExpression> expr, enum UnaryOp op)
	:AbstractExpression("UnaryExpression")
{
	this->expr = expr;
	this->setType(expr->getValue().getValue().first);
	this->op = op;
}

UnaryExpression::~UnaryExpression()
{

}

UnaryOp UnaryExpression::getOp() const
{
	return this->op;
}

void UnaryExpression::printOperator() const
{
	switch(op)
	{
		case UMINUS:
			std::cout << "-" ;
			break;
		case UPLUS:
			std::cout << "+" ;
			break;
		case UBITN:
			std::cout << "~" ;
			break;
		case UBOOLN:
			std::cout << "!" ;
			break;
		default:
			std::cerr << "UnaryExpression::printOperator() : ERROR unknown op" << std::endl;
	}
}

void UnaryExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;

    for (int i = 0; i < tabulationNumber + 1; i++)
    {
        std::cout << "  ";
    }
    printOperator();
    std::cout << std::endl;
    expr->printTree(tabulationNumber + 1);
}

Value UnaryExpression::evaluate() const
{
	Value exprVal = this->expr->evaluate();
	Value ret;
	switch(op)
	{
		case UMINUS:
			ret = Value( exprVal.getValue().first, -(exprVal.getValue().second) ) ;
			break;
		case UPLUS:
			ret = Value( exprVal.getValue().first, exprVal.getValue().second ) ;
			break;
		case UBITN:
			ret = Value( exprVal.getValue().first, ~(exprVal.getValue().second) ) ;
			break;
		case UBOOLN:
			ret = Value( exprVal.getValue().first, !(exprVal.getValue().second) ) ;
			break;
		default:
			std::cerr << "UnaryExpression::evaluate() : ERROR unknown op" << std::endl;
	}
	return ret;
}

IR::sh_Memory UnaryExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	IR::Generator gen; 
	IR::sh_Memory leftMem = this->expr->buildIR(currentBasicBlock); 
	IR::Type irType = this->expr->getValue().getIRType(); 
	IR::sh_Memory destMem = gen.getNewUnusedMemmory(irType); 
	std::list<IR::sh_AbsInstruction> instructionsList = gen.unaryOperator(leftMem, destMem, op); 
	currentBasicBlock->pushInstructionBack(instructionsList); 
	return destMem; 
}
