#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <list>
#include <memory>
#include <map>

#include "../instructions/AbstractInstruction.h"
#include "../data/Memory.h"
#include "../data/Register.h"

namespace IR {

    class BasicBlock
    {
    public:
        BasicBlock();

        void pushInstructionBack(sh_AbsInstruction instruction);
        void pushInstructionBack(std::list<sh_AbsInstruction> instructions);
        void setEndConditionnalInstruction(sh_AbsInstruction conditionalInstruction);

        void insertNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock);
        void insertNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock);

        void setNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock);
        void setNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock);

    private:
        std::list<sh_AbsInstruction> instructionsList;
        sh_AbsInstruction endConditionnalInstruction;
        std::shared_ptr<BasicBlock> nextBlockTrue;
        std::shared_ptr<BasicBlock> nextBlockFalse;

        std::map<std::string, sh_Memory> usedMemory;
        std::map<std::string, sh_Register> usedRegister;
    };
}



#endif // BASICBLOCK_H
