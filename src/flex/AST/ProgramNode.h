
#ifndef PROGRAM_NODE_H
#define PROGRAM_NODE_H


#include "AbstractNode.h"
#include "../../IR/basicBlock/FunctionStructure.h"

namespace AST {
	
	class FunctionDeclaration;
	class SequenceInstruction;
	
    class ProgramNode : public AbstractNode
    {
    public:
    
        ProgramNode(std::shared_ptr<SequenceInstruction> liextBefore, std::shared_ptr<FunctionDeclaration> main, std::shared_ptr<SequenceInstruction> liextAfter);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const; // should not be used => throw an error
        std::shared_ptr<IR::FunctionStructure> buildIR() const;

    private:
        std::shared_ptr<SequenceInstruction> liextBefore;
        std::shared_ptr<SequenceInstruction> liextAfter;
        std::shared_ptr<FunctionDeclaration> main;

    };
}


#endif // PROGRAM_NODE_H
