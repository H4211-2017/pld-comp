#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <list>
#include <memory>
#include <map>

#include "../instructions/AbstractInstruction.h"
#include "../data/Memory.h"
#include "../data/Register.h"

namespace IR {

    class BasicBlock;
    typedef std::shared_ptr<BasicBlock> sh_BasicBlock;

    class BasicBlock : public std::enable_shared_from_this<BasicBlock>
    {
    public:
        BasicBlock();

        void pushInstructionBack(sh_AbsInstruction instruction);
        void pushInstructionBack(std::list<sh_AbsInstruction> instructions);
        void setEndConditionnalInstruction(sh_AbsInstruction conditionalInstruction);

        void insertNextBlockTrue(sh_BasicBlock basicBlock);
        void insertNextBlockFalse(sh_BasicBlock basicBlock);

        void setNextBlockTrue(sh_BasicBlock basicBlock);
        void setNextBlockFalse(sh_BasicBlock basicBlock);

        void updateChildsPreviousBlock();

    private:
        std::list<sh_AbsInstruction> instructionsList;
        sh_AbsInstruction endConditionnalInstruction;
        sh_BasicBlock nextBlockTrue;
        sh_BasicBlock nextBlockFalse;
        std::list<sh_BasicBlock> previousBlocks;

        std::map<std::string, sh_AbstractData> usedMemory;
        std::map<std::string, sh_Register> usedRegister;
    };


}



#endif // BASICBLOCK_H
