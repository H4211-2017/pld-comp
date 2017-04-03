#include <algorithm>
#include <iostream>
#include <assert.h>
#include <deque>

#include "../config/config.h"
#include "FunctionBlock.h"

using namespace IR;

FunctionBlock::FunctionBlock(std::string name): AbstractFunction(name)
{
    functionInit = std::make_shared<BasicBlock>();
    functionCore = std::make_shared<BasicBlock>();
    functionReturn = std::make_shared<BasicBlock>();

    functionInit->setNextBlockTrue(functionCore);
    functionCore->setNextBlockTrue(functionReturn);
}

/**
 * @brief FunctionBlock::generateBasicBlockList set coreList content
 */
void FunctionBlock::generateBasicBlockList()
{
    coreList.clear();
    exploreBasicBlock(functionInit);
}

/**
 * @brief FunctionBlock::affectPreviousBasicBlock ask every basic block of the function to set himself as the previous of his childs
 * @remark The list of function basic block must be generated (FunctionBlock::generateBasicBlockList())
 */
void FunctionBlock::affectPreviousBasicBlock()
{
    functionInit->updateChildPreviousBlock();
    for(sh_BasicBlock bb : coreList)
    {
        bb->updateChildPreviousBlock();
    }
}

/**
 * @brief FunctionBlock::getMemoryFromBasicBlock get the memory used by every basic block
 * @remark The list of function basic block must be generated (FunctionBlock::generateBasicBlockList())
 */
void FunctionBlock::getMemoryFromBasicBlock()
{
    usedMemory.clear();
    for(sh_BasicBlock bb : coreList)
    {
        for(auto data : bb->getUsedMemory())
        {
            //fill the map with data from every basicblocks
            usedMemory[data.first] = data.second;
        }
    }
}

/**
 * @brief FunctionBlock::aliveRegistryDetection set the list of alive registry
 * of every instructions of the function, by calling exploreBasicBlockToFindAliveRegister.
 * @remarks The list of function basic block must be generated (FunctionBlock::generateBasicBlockList())
 * @remarks The previous basic block of every core basic block must be set
 */
void FunctionBlock::aliveRegistryDetection()
{
    std::map<std::string, sh_Register> aliveRegisters;
    std::map<std::string, sh_BasicBlock> greyBasicBlock;
    exploreBasicBlockToFindAliveRegister(this->functionReturn, aliveRegisters, greyBasicBlock);
}

/**
 * @brief FunctionBlock::affectRegistry affect registry to every basic block of the function
 * @param asmRegistryAvailable list of the available register name in ASM
 * @remarks The end of this function is not guarranted but I never found an example of such case...
 * @remarks The list of function basic block must be generated (FunctionBlock::generateBasicBlockList())
 * @remarks The basic block must have their alive registry set (FunctionBlock::aliveRegistryDetection())
 */
void FunctionBlock::affectRegistry(std::queue<std::string> asmRegistryAvailable)
{
    std::list<sh_BasicBlock> waitingForAffectation = coreList;
    while (waitingForAffectation.size() > 0) {
        for(auto it=waitingForAffectation.begin() ; it!=waitingForAffectation.end() ; it++)
        {
            const sh_BasicBlock &bb = *it;
            //if the current basic block is ready
            if(bb->isRegistryAfectable())
            {
                //then affect his register
                bb->affectRegistry(asmRegistryAvailable);
                //save the value of it
                auto newIt = it;
                newIt--;
                //erase the basic block from the list
                waitingForAffectation.erase(it);
                //set back a safe value to it
                it = newIt;
            }
        }
        //do that again until no more basic block left...
    }

}

/**
 * @brief FunctionBlock::affectMemory set base pointer offset for every Memory of the function.
 * @remark FunctionBlock::getMemoryFromBasicBlock() must be run before calling this function.
 */
void FunctionBlock::affectMemory()
{
    std::list<sh_Memory> memoryList;
    //copy the memory map to a memory list
    for(auto pair : usedMemory)
    {
        const sh_Memory &mem = pair.second;
        memoryList.push_back(mem);
    }
    //sort the list so that the smaller element come first
    memoryList.sort([](const sh_AbstractData &a, const sh_AbstractData &b)
                            {return a->getSizeInMemory() < b->getSizeInMemory();});
    int currentOffset = FIRST_MEMORY_FUNCTION_OFFSET;
    //affect an offset to each memory
    for(sh_Memory mem : memoryList)
    {
        //move the offset to the next (1/2/4) byte depending on the data type
        currentOffset -= (-currentOffset) % mem->getType();
        mem->setAsmBasePointerOffset(currentOffset);
        currentOffset -= mem->getSizeInMemory();
    }
}

sh_BasicBlock FunctionBlock::getFunctionCore() const
{
    return functionCore;
}

void FunctionBlock::setFunctionCore(const sh_BasicBlock &value)
{
    functionCore = value;
    functionInit->setNextBlockTrue(functionCore);
}

std::list<sh_BasicBlock> FunctionBlock::getCoreList() const
{
    return coreList;
}

void FunctionBlock::printIR(std::ostream & os) const
{
    //the first basicBlock of the list is the functionInit
    for(sh_BasicBlock bb : coreList)
    {
        bb->printIr(os);
    }
}

void FunctionBlock::printASM(std::ostream &os, AsmType asmType) const
{
    printASMprolog(os,asmType);
    //the first basicBlock of the list is the functionInit
    for(sh_BasicBlock bb : coreList)
    {
        bb->printAsm(os, asmType);
    }
}

void FunctionBlock::generateIR()
{
    generateBasicBlockList();
}

/**
 * @brief FunctionBlock::generateASM Generate the asm of the given type of this function.
 * @param asmType the type of ASM wanted.
 * @remark This function must be called only once ! the beaviour is undefined if multliple call
 * are made on the same object.
 */
void FunctionBlock::generateASM(AsmType asmType)
{
    generateBasicBlockList();
    affectPreviousBasicBlock();
    getMemoryFromBasicBlock();
    aliveRegistryDetection();
    affectMemory();
    std::deque<std::string> regList;
    switch (asmType) {
    case AsmType::X86Linux:
        regList = ASM_X86_REGISTER_LIST;
        break;
    default:
        std::cerr << "Unknow ASM type: " << asmType << std::endl;
        exit(-1);
        break;
    }
    std::queue<std::string> regQueue(regList);
    affectRegistry(regQueue);
}

/**
 * @brief FunctionBlock::exploreBasicBlock add the current block and is childs (recursively) to the coreList.
 * @param currentBlock block where the exploration start.
 */
void FunctionBlock::exploreBasicBlock(sh_BasicBlock currentBlock)
{
    coreList.push_back(currentBlock);
    //if the current block is not the epiloge and as no following block, link to epiloge
    if(currentBlock->getNextBlockFalse() == nullptr && currentBlock->getNextBlockTrue() == nullptr && currentBlock != functionReturn)
    {
        currentBlock->setNextBlockTrue(functionReturn);
    }

    sh_BasicBlock nextBlock = currentBlock->getNextBlockTrue();
    if(nextBlock != nullptr && !isBasicBlockAlreadyExplored(nextBlock))
    {
        exploreBasicBlock(nextBlock);
    }
    nextBlock = currentBlock->getNextBlockFalse();
    if(nextBlock != nullptr && !isBasicBlockAlreadyExplored(nextBlock))
    {
        exploreBasicBlock(nextBlock);
    }
}

/**
 * @brief FunctionBlock::isBasicBlockAlreadyExplored check if the given block is on the coreList list.
 * @param currentBlock the block to look for.
 * @return true if the block is in the coreList list.
 */
bool FunctionBlock::isBasicBlockAlreadyExplored(sh_BasicBlock currentBlock) const
{
    auto it = std::find(coreList.begin(), coreList.end(), currentBlock);
    return it != coreList.end();
}

/**
 * @brief FunctionBlock::exploreBasicBlockToFindAliveRegister bottom up algorithm to detect alive registry.
 * The algorithm is performed on the given basic block and then is called recursivly (if needed) on
 * the previous basic block of the given one.
 * @param basicBlock the basic block one whith the algorithm is run
 * @param aliveRegister the map of alive register when entering the given basic block
 * @remark The list of basic block must be set before execution (FunctionBlock::generateBasicBlockList())
 */
void FunctionBlock::exploreBasicBlockToFindAliveRegister(sh_BasicBlock basicBlock, std::map<std::string,sh_Register> aliveRegister, std::map<std::string, sh_BasicBlock> & greyBasicBlock)
{
    bool changeDuringLoop = false;
    //if the basic block use a regsiter for is jump
    if(basicBlock->isConditionnal())
    {
        //se this register as alive
        const sh_Register &reg = basicBlock->getConditionnalJumpRegister();
        aliveRegister[reg->getName()] = reg;
    }
    auto instList = basicBlock->getInstructionsList();
    //loop on every basic block instruction from the last one to the first (using reverse iterator)
    for(auto it = instList.rbegin() ; it != instList.rend() ; it++ )
    {
        sh_AbsInstruction & inst = *it;
        //remove the wrote registry from the alive list (map)
        for(sh_Register reg : inst->getWroteRegisterList())
        {
            auto it = aliveRegister.find(reg->getName());
            assert(it != aliveRegister.end()); // reg must be alive ! (optimisation may create unused register)
            aliveRegister.erase(it);
        }
        //add the read registry to the alive list (map)
        for(sh_Register reg : inst->getReadRegisterList())
        {
            aliveRegister[reg->getName()] = reg;
        }

        //add the current alive register to the instruction alive register list (map)
        for(std::pair<std::string, sh_Register> pair : aliveRegister)
        {
            //if the register was not already on the inst alive register list set changeDuringLoop to true
            if(inst->pushToAliveRegister(pair.second))
            {
                changeDuringLoop = true;
            }
        }
    }
    //if it's the first passage on this block or
    //if something s changed during this loop we must propage the change to the previous blocks (recursive call)
    if( (changeDuringLoop == true || greyBasicBlock.find(basicBlock->getName()) == greyBasicBlock.end()) && basicBlock != functionInit)
    {
        //add the current basic block to the seen list
        greyBasicBlock[basicBlock->getName()] = basicBlock;
        //run (or re-run) the exploration on the previous basic blocks
        //performance optimisation: find less ordering
        for(sh_BasicBlock nextBB : basicBlock->getPreviousBlocks())
        {
            //explore with the current alive register
            exploreBasicBlockToFindAliveRegister(nextBB, aliveRegister, greyBasicBlock);
        }
    }
}

void FunctionBlock::printASMprolog(std::ostream &os, AsmType asmType) const
{
    switch (asmType) {
    case AsmType::X86Linux:
        os << this->getFunctionName() << ":" << std::endl;
        os << "\tpush\t%rbp" << std::endl;
        os << "\tmovq\%rsp, %rbp" << std::endl;
        break;
    default:
        break;
    }
}

void FunctionBlock::printASMepilog(std::ostream &os, AsmType asmType) const
{
    switch (asmType) {
    case AsmType::X86Linux:
        os << "\tpopq\t%rbp" << std::endl;
        os << "\tret" << std::endl;
        break;
    default:
        break;
    }
}

std::shared_ptr<const BasicBlock> FunctionBlock::getFunctionReturn() const
{
    return functionReturn;
}
















