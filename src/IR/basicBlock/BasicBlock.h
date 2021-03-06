#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <list>
#include <memory>
#include <map>
#include <queue>

#include "../instructions/AbstractInstruction.h"
#include "../data/Memory.h"
#include "../data/Register.h"
#include "../config/Enums.h"

namespace IR {

    enum class Flag
    {
        None,
        LoopCondition,
        LoopEnd
    };

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
        void affectRegistry(std::queue<std::string> availableAsmRegistry, OptimisationLevel opLvl=OptimisationLevel::O0);
        bool isRegistryAfectable() const;

        void printIr(std::ostream& os) const;
        void printAsm(std::ostream& os, AsmType asmType) const;

        std::string getName() const;
        void setName(const std::string &value);

        sh_BasicBlock getNextBlockTrue() const;
        sh_BasicBlock getNextBlockFalse() const;
        std::map<std::string, sh_Memory> getUsedMemory() const;
        std::list<sh_AbsInstruction> &getInstructionsList();
        std::list<sh_BasicBlock> getPreviousBlocks() const;
        sh_Register getConditionnalJumpRegister() const;

        bool isConditionnal() const;

        void setBasicBlockFlag(const Flag &value);
        Flag getBasicBlockFlag() const;




    private:
        void printAsmLabel(std::ostream& os, AsmType asmType) const;
        void printAsmJump(std::ostream& os, AsmType asmType) const;

    private:
        std::string name;
        Flag basicBlockFlag;
        std::list<sh_AbsInstruction> instructionsList;
        sh_BasicBlock nextBlockTrue;
        sh_BasicBlock nextBlockFalse;
        std::list<sh_BasicBlock> previousBlocks;

        std::map<std::string, sh_Memory> usedMemory;
        std::map<std::string, sh_Register> usedRegister;

        sh_Register conditionnalJumpRegister;
    };




}



#endif // BASICBLOCK_H
