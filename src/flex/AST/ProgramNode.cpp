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
    std::shared_ptr<IR::ProgrameStructure> programStructure = std::make_shared<IR::ProgrameStructure>();

    for (std::shared_ptr<FunctionDeclaration> astFunction : liextBefore->getListFunctionDeclaration())
    {
        programStructure->addFunction(astFunction->getIrFunction());
    }
    for (std::shared_ptr<FunctionDeclaration> astFunction : liextAfter->getListFunctionDeclaration())
    {
        programStructure->addFunction(astFunction->getIrFunction());
    }
    programStructure->addFunction(main->getIrFunction());

    IR::sh_BasicBlock mainCoreIR = main->getIrFunction()->getFunctionCore();
    main->buildIR(mainCoreIR);
    
    return programStructure;
}
