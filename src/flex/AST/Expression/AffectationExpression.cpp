#include "AffectationExpression.h"
#include "AddExpression.h"
#include "IDExpression.h"
#include "BitwiseAndExpression.h"
#include "BitwiseOrExpression.h"
#include "BitwiseShiftLeftExpression.h"
#include "BitwiseXorExpression.h"
#include "ModuloExpression.h"
#include "DivExpression.h"
#include "MultExpression.h"
#include "SubExpression.h"

#include "../../../IR/generator/Generator.h"

using namespace AST;

AffectationExpression::AffectationExpression()
    : AbstractExpression("AffectationExpression")
{
	
}

AffectationExpression::AffectationExpression(std::string id, enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope)
    : AbstractExpression("AffectationExpression")
{
	var = scope->findVariable(id);
	switchOperatorMake(op, rightMember, scope);
	
}


AffectationExpression::AffectationExpression(std::shared_ptr<Variable> variable, enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope)
    : AbstractExpression("AffectationExpression")
{
	var = variable;
	switchOperatorMake(op, rightMember, scope);
}

AffectationExpression::~AffectationExpression()
{

}

Value AffectationExpression::evaluate() const
{
    Value val = this->transformedExpr->evaluate();
    return val;
}

IR::sh_Memory AffectationExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    IR::Generator gen;
    IR::sh_Memory leftMem = var->buildIR(currentBasicBlock);
    IR::sh_Memory rightMem = transformedExpr->buildIR(currentBasicBlock);
    std::list<IR::sh_AbsInstruction> absIntructions = gen.setValue(rightMem, leftMem);
    currentBasicBlock->pushInstructionBack(absIntructions);
    return rightMem;
}

void AffectationExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;

    this->var->printTree(tabulationNumber + 1);
    std::cout << std::endl;

    this->transformedExpr->printTree(tabulationNumber + 1);
}

void AffectationExpression::switchOperatorMake(enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope)
{
	switch(op)
	{
		
		case AFFECT :
			this->transformedExpr = rightMember;
			var->noLongerDeclaration();
			break;
		case AFFECT_MULT :
			this->transformedExpr = std::make_shared<MultExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_DIV :
			this->transformedExpr = std::make_shared<DivExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_ADD :
			this->transformedExpr = std::make_shared<AddExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_SUB :
			this->transformedExpr = std::make_shared<SubExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_MOD :
			this->transformedExpr = std::make_shared<ModuloExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_BIT_AND :
			this->transformedExpr = std::make_shared<BitwiseAndExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_BIT_OR :
			this->transformedExpr = std::make_shared<BitwiseOrExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_BIT_XOR :
			this->transformedExpr = std::make_shared<BitwiseXorExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_BIT_LEFT_SHIFT :
			this->transformedExpr = std::make_shared<BitwiseShiftLeftExpression>(std::make_shared<IDExpression>(var, scope), rightMember);
			break;
		case AFFECT_BIT_RIGHT_SHIFT :
			break;
		default :
			break;
	}
	
	this->setType(this->transformedExpr->getValue().getValue().first);
}
