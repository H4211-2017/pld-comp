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

        void insertNextBlockTrue(sh_BasicBlock basicBlock);
        void insertNextBlockFalse(sh_BasicBlock basicBlock);

        void setNextBlockTrue(sh_BasicBlock basicBlock);
        void setNextBlockFalse(sh_BasicBlock basicBlock);

        void updateChildPreviousBlock();

        void printIr(std::ostream& os) const;

        std::string getName() const;
        void setName(const std::string &value);

        sh_BasicBlock getNextBlockTrue() const;
        sh_BasicBlock getNextBlockFalse() const;
        std::map<std::string, sh_AbstractData> getUsedMemory() const;
        std::list<sh_AbsInstruction> getInstructionsList() const;
        std::list<sh_BasicBlock> getPreviousBlocks() const;

    private:


    private:
        std::string name;
        std::list<sh_AbsInstruction> instructionsList;
        sh_BasicBlock nextBlockTrue;
        sh_BasicBlock nextBlockFalse;
        std::list<sh_BasicBlock> previousBlocks;

        std::map<std::string, sh_AbstractData> usedMemory;
        std::map<std::string, sh_Register> usedRegister;

        sh_Register conditionnalJumpRegister;
    };


}



#endif // BASICBLOCK_H
