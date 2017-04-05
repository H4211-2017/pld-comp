#include "ProgramNode.h"

#include "Instruction/SequenceInstruction.h"
#include "Function/FunctionDeclaration.h"

using namespace AST;

ProgramNode::ProgramNode(std::shared_ptr<SequenceInstruction> liextBefore, std::shared_ptr<FunctionDeclaration> main, std::shared_ptr<SequenceInstruction> liextAfter)
	: AbstractNode("ProgramNode")
{
	this->liextBefore = liextBefore;
	this->liextAfter = liextAfter;
	this->main = main;
}

void ProgramNode::printTree(int tabulationNumber) const
{
    std::cout << std::endl << std::endl << "========= PRINT TREE =========" << std::endl;
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;

    liextBefore->printTree(tabulationNumber + 1);
    std::cout << std::endl;
    main->printTree(tabulationNumber + 1);
    std::cout << std::endl;
    liextAfter->printTree(tabulationNumber + 1);
}

Value ProgramNode::evaluate() const
{
	return Value();
}

// TODO : functions other than main
IR::sh_ProgrameStructure ProgramNode::buildIR()
{
    std::cout << "ProgramNode::buildIR : main : " << main << std::endl;
    std::cout << "ProgramNode::buildIR avant creation programStructure " << std::endl;
    std::shared_ptr<IR::ProgrameStructure> programStructure = std::make_shared<IR::ProgrameStructure>();
    std::cout << "ProgramNode::buildIR apres creation programStructure " << std::endl;
    programStructure->addFunction(main->getIrFunction());
    std::cout << "ProgramNode::buildIR apres addFunction programStructure " << std::endl;
    std::cout << "ProgramNode::buildIR : main->getIrFunction() : " << main->getIrFunction() << std::endl;
    IR::sh_BasicBlock mainCoreIR = main->getIrFunction()->getFunctionCore();
    std::cout << "ProgramNode::buildIR apres mainCoreIR " << std::endl;
    main->buildIR(mainCoreIR);
    std::cout << "ProgramNode::buildIR apres main->buildIR" << std::endl;
    
    return programStructure;
}
