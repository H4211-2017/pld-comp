#ifndef IR_FUNCTIONBLOCK_H
#define IR_FUNCTIONBLOCK_H

#include <memory>
#include <queue>
#include <list>

#include "AbstractFunction.h"
#include "../basicBlock/BasicBlock.h"

namespace IR {

    enum class OptimisationLevel{
        O0 = 0,
        O1 = 1,
        O2 = 2
    };

    class FunctionBlock : public AbstractFunction
    {
    public:
        FunctionBlock(std::string name, Type returnType, std::list<sh_AbstractData> param = std::list<sh_AbstractData>());

        sh_BasicBlock getFunctionCore() const;
        void setFunctionCore(const sh_BasicBlock &value);

        std::list<sh_BasicBlock> getCoreList() const;
        std::shared_ptr<const BasicBlock> getFunctionReturn() const;

        void printIR(std::ostream &os) const;
        void printASM(std::ostream &os, AsmType asmType) const;
        void generateIR();
        void generateASM(AsmType asmType, OptimisationLevel opLvl = OptimisationLevel::O0);

    protected:
        void generateBasicBlockList();
        void affectPreviousBasicBlock();
        void getMemoryFromBasicBlock();
        void aliveRegistryDetection();
        void affectRegistry(std::queue<std::string> asmRegistryAvailable);
        void affectMemory();
        void manageReturnStatements();
        void removeEmptyBasicBlock();
        void removeUnreadMemory();

        sh_BasicBlock closestLoop(const sh_BasicBlock &source);

        void exploreBasicBlock(sh_BasicBlock currentBlock);
        bool isBasicBlockAlreadyExplored(sh_BasicBlock currentBlock) const;

        void exploreBasicBlockToFindAliveRegister(sh_BasicBlock basicBlock, std::map<std::string, sh_Register> aliveRegister, std::map<std::string, sh_BasicBlock> &greyBasicBlock);

        void printASMprolog(std::ostream &os, AsmType asmType) const;
        void printASMepilog(std::ostream &os, AsmType asmType) const;

    private:
        void init();

        sh_BasicBlock functionInit;
        sh_BasicBlock functionCore;
        sh_BasicBlock functionReturn;

        sh_Memory returnedMemory;

        std::list<sh_BasicBlock> coreList;

        std::map<std::string,sh_Memory> usedMemory;
    };

    typedef std::shared_ptr<FunctionBlock> sh_FunctionBlock;
}

#endif // IR_FUNCTIONBLOCK_H
