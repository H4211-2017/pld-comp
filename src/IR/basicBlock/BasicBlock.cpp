#include <algorithm>
#include <iostream>
#include <assert.h>

#include "BasicBlock.h"
#include "../config/Enums.h"
#include "../instructions/ReadFromMemory.h"
#include "../instructions/WriteToMemory.h"
#include "../instructions/Call.h"

using namespace IR;

BasicBlock::BasicBlock()
{
    static int basicBlockNumber = 0;
    name = ".BB";
    name.append( std::to_string(basicBlockNumber) );
    basicBlockNumber++;
    basicBlockFlag = Flag::None;
}

/**
 * @brief BasicBlock::insertNextBlockFalse insert the given BasicBlock as next false block
 *        and set the old next false block as the given BasicBlock next false block.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::insertNextBlockFalse(sh_BasicBlock basicBlock)
{
    basicBlock->setNextBlockTrue(this->nextBlockFalse);
    basicBlock->setNextBlockFalse(nullptr);
    //set the false next block
    this->setNextBlockFalse(basicBlock);
}

/**
 * @brief BasicBlock::insertNextBlockTrue insert the given BasicBlock as next true block
 *        and set the old next true block as the given BasicBlock next true block.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::insertNextBlockTrue(sh_BasicBlock basicBlock)
{
    basicBlock->setNextBlockTrue(this->nextBlockFalse);
    basicBlock->setNextBlockFalse(nullptr);
    this->setNextBlockTrue(basicBlock);
}

/**
 * @brief BasicBlock::setNextBlockFalse insert the given BasicBlock as next false block discarding the old one.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::setNextBlockFalse(sh_BasicBlock basicBlock)
{
    //if the end of the basic block is conditionnal
    if(nextBlockTrue != nullptr && basicBlock != nullptr)
    {
        if(conditionnalJumpRegister != nullptr)
        {
            conditionnalJumpRegister->incrementReadCount();
        }
    }
    //the basic block was conditionnal but is no more
    else if(basicBlock == nullptr && nextBlockFalse != nullptr)
    {
        if(conditionnalJumpRegister != nullptr)
        {
            conditionnalJumpRegister->decrementReadCount();
        }
    }
    //finaly set the value
    this->nextBlockFalse = basicBlock;
}

/**
 * @brief BasicBlock::setNextBlockTrue insert the given BasicBlock as next true block discarding the old one.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::setNextBlockTrue(sh_BasicBlock basicBlock)
{
    //if the end of the basic block is conditionnal
    if(nextBlockFalse != nullptr && basicBlock != nullptr)
    {
        if(conditionnalJumpRegister != nullptr)
        {
            conditionnalJumpRegister->incrementReadCount();
        }
    }
    //the basic block was conditionnal but is no more
    else if(basicBlock == nullptr && nextBlockTrue != nullptr)
    {
        if(conditionnalJumpRegister != nullptr)
        {
            conditionnalJumpRegister->decrementReadCount();
        }
    }
    //finaly set the value
    this->nextBlockTrue = basicBlock;
}

/**
 * @brief BasicBlock::pushInstructionBack push_back an instruction to the block instruction list.
 * @param instruction the instruction to add
 */
void BasicBlock::pushInstructionBack(sh_AbsInstruction instruction)
{
    this->instructionsList.push_back(instruction);

    //add used memory/register to the map of this basicBlock
    for(sh_Memory mem : instruction->getReadMemoryList())
    {
        usedMemory[mem->getName()] = mem;
    }
    for(sh_Memory mem : instruction->getWroteMemoryList())
    {
        usedMemory[mem->getName()] = mem;
    }

    for(sh_Register reg : instruction->getReadRegisterList())
    {
        usedRegister[reg->getName()] = reg;
    }
    for(sh_Register reg : instruction->getWroteRegisterList())
    {
        usedRegister[reg->getName()] = reg;
    }

    //set the conditionnal register using the register wrote by this instruciton (if it exist)
    //the first register is used as no instruction can wrote two register
    if(instruction->getWroteRegisterList().size() > 0)
    {
        //if the register was already set decrement its read number value
        if(isConditionnal() && conditionnalJumpRegister != nullptr)
        {
            conditionnalJumpRegister->decrementReadCount();
        }
        conditionnalJumpRegister = instruction->getWroteRegisterList().front();
        if(isConditionnal())
        {
            conditionnalJumpRegister->incrementReadCount();
        }
    }
}

/**
 * @brief BasicBlock::pushInstructionBack push_back a list of instruction to the block instruction list.
 * @param instructions list of instruction to add
 */
void BasicBlock::pushInstructionBack(std::list<sh_AbsInstruction> instructions)
{
    for(auto instruction : instructions)
    {
        pushInstructionBack(instruction);
    }
}

/**
 * @brief BasicBlock::updateChildPreviousBlock update the previous block list of the two child
 * of this block.
 * Compartement is unknow if called a second time.
 * (must be call only once the basic block tree is finished)
 */
void BasicBlock::updateChildPreviousBlock()
{
    //insert in the False next block
    if(nextBlockFalse != nullptr)
    {
        //insert in the list (do not check if not already in the list)
        nextBlockFalse->previousBlocks.push_back(this->shared_from_this());
    }
    //insert in the True next block
    if(nextBlockTrue != nullptr)
    {
        //insert in the list (do not check if not already in the list)
        nextBlockTrue->previousBlocks.push_back(this->shared_from_this());
    }
}

/**
 * @brief BasicBlock::affectRegistry affect registry on the current BasicBlock.
 * @param availableAsmRegistry list of the available registry for affectation
 * @remark This require the alive register to be set for every instructions and
 * the alive registry of this block to have their asm name set (can be checked
 * using BasicBlock::isRegistryAfectable)
 */
void BasicBlock::affectRegistry(std::queue<std::string> availableAsmRegistry, OptimisationLevel opLvl)
{
    if(instructionsList.size() == 0)
        return;
    ///Init: set list as they must be
    //get the list of alive register at the begining of the block form it first instruction
    std::list<sh_Register> aliveRegisters;
    const sh_AbsInstruction &firstInstruction = *instructionsList.begin();
    const std::map<std::string, sh_Register> &aliveMap = firstInstruction->getAliveRegister();
    transform(aliveMap.begin(),
              aliveMap.end(),
              back_inserter(aliveRegisters),
              [](const std::map<std::string, sh_Register>::value_type& val){return val.second;} );
    //if BasicBlock::isRegistryAfectable() is called before execution, this should never be false
    assert(aliveMap.find("") == aliveMap.end());
    //remove from the queue the used register
    unsigned sizeOfList = availableAsmRegistry.size(); //copy the value as the size of the list may change during loop
    for(unsigned i=0 ; i<sizeOfList ; i++)
    {
        const std::string &regAsmName = availableAsmRegistry.front();

        //if regAsmName is afected to one alive register, this name in not available
        if(aliveMap.find(regAsmName) != aliveMap.end())
        {
            availableAsmRegistry.pop();
        }
        else
        {
            //else the name can be used, we push it back to the end of the queue
            availableAsmRegistry.pop();
            availableAsmRegistry.push(regAsmName);
        }
    }
    ///Define data sruct used for O2 optimisation
    std::map<std::string,sh_Register> lastRegForAsmName;
    std::map<sh_Memory,sh_Register> lastRegForMemory;
    ///Affect asm name the registry
    for(auto instIt=instructionsList.begin() ; instIt!=instructionsList.end() ; instIt++)
    {
        sh_AbsInstruction inst = *instIt;
        //update avaibleRegistry queue by adding now unused register
        for(std::list<sh_Register>::iterator it=aliveRegisters.begin() ; it!=aliveRegisters.end() ; it++)
        {
            const sh_Register &reg = *it;
            const auto instAliveRegister = inst->getAliveRegister();
            //if the alive register is not in the inst alive register list
            if(instAliveRegister.find(reg->getName()) == instAliveRegister.end())
            {
                //save iterator to allow for loop to continue properly
                auto newIt = it;
                newIt--;
                //add the unused register asm name to the available register name
                availableAsmRegistry.push((*it)->getAsmRegisterName());
                //remove the register from alive register list
                aliveRegisters.erase(it);
                //set it back to a valid value
                it = newIt;
            }
        }
        //if we are in a O2 or more optimisation level
        if(opLvl > OptimisationLevel::O1)
        {
            //if the instruction is a memory read,
            if(std::dynamic_pointer_cast<ReadFromMemory>(inst))
            {
                sh_Register dest = inst->getWroteRegisterList().front();
                sh_Memory source = inst->getReadMemoryList().front();
                //look if we find a register with the wanted value
                sh_Register lastRegForSource = lastRegForMemory.find(source)->second;
                if(lastRegForSource != nullptr)
                {
                    //if the wanted register is still in memory (not erased yet)
                    sh_Register lastRegForAsmNameOfSourceReg = lastRegForAsmName.find(lastRegForSource->getAsmRegisterName())->second;
                    if(lastRegForSource == lastRegForAsmNameOfSourceReg)
                    {
                        //then we can set the same asmName to the dest reg
                        dest->setAsmRegisterName(lastRegForSource->getAsmRegisterName());
                        //remove the now useless read from memory instruction from this basicblock
                        auto previousInstIt = instIt;
                        previousInstIt--;
                        instructionsList.erase(instIt);
                        instIt = previousInstIt;
                    }
                }
                //then update lastRegForMemory map
                lastRegForMemory[source] = dest;
            }
            //if the instruction is a memory write
            if(std::dynamic_pointer_cast<WriteToMemory>(inst))
            {
                sh_Register reg = inst->getReadRegisterList().front();
                sh_Memory mem = inst->getWroteMemoryList().front();
                //then update lastRegForMemory map
                lastRegForMemory[mem] = reg;
            }
            //if we are in an Call, all register can be erased (or will) so clean every thing
            if(std::dynamic_pointer_cast<Call>(inst))
            {
                lastRegForMemory.clear();
                lastRegForAsmName.clear();
            }
        }
        //affect registry to newly used register
        for(sh_Register reg : inst->getWroteRegisterList())
        {
            //if we wrote into a register and it does'nt have an ASM name yet, we give it one
            if(reg->getAsmRegisterName() == "" )
            {
                //give an asm name to the register
                std::string regName = availableAsmRegistry.front();
                reg->setAsmRegisterName(regName);
                availableAsmRegistry.pop();
                //add it to the alive register list
                aliveRegisters.push_back(reg);
                //update the map of asm name to IR register
                lastRegForAsmName[regName] = reg;
            }
        }

    }
}

/**
 * @brief BasicBlock::isRegistryAfectable check if BasicBlock::affectRegistry can be called
 * @return true if the block can give adresse to his registry.
 * (i.e. if the alive registry at block start have their asm name set)
 */
bool BasicBlock::isRegistryAfectable() const
{
    if(instructionsList.size() == 0)
    {
        return true;
    }
    //alive register at the block start are the ones alive for first instruction
    const sh_AbsInstruction &firstInstruction = *instructionsList.begin();
    //for every alive register check if it has a asm name
    for(auto pair : firstInstruction->getAliveRegister())
    {
        const sh_Register &reg = pair.second;
        if(reg->getAsmRegisterName() == "")
        {
            //if one of the needed alive register is not yet set this block cannot affect his register properly
            //registery must by set first
            return false;
        }
    }
    //every alive registry are set, this block is ready
    return true;
}

/**
 * @brief BasicBlock::printIr print to the given stream the IR code of the basic block
 * @param os stream where the IR code will be printed
 */
void BasicBlock::printIr(std::ostream &os) const
{
    os << "label: " << name << std::endl;

    for(sh_AbsInstruction inst : instructionsList )
    {
        os << inst->toString() << std::endl;
    }

    if(nextBlockFalse == nullptr && nextBlockTrue == nullptr)
    {
        //if none of the two posibility is set

    }
    //if only one is set, no need to check any things
    else if(nextBlockFalse != nullptr && nextBlockTrue == nullptr)
    {
        os << "Jump to: " << nextBlockFalse->getName() << std::endl;
    }
    else if((nextBlockFalse == nullptr && nextBlockTrue != nullptr) || conditionnalJumpRegister == nullptr)
    {
        os << "Jump to: " << nextBlockTrue->getName() << std::endl;
    }
    else
    {
        //else the two are set, need to do a conditionnal jump
        os << "if " << conditionnalJumpRegister->getName() << " == 0 -> Jump to: "
           << nextBlockFalse->getName() << " (False block)" << std::endl;
        os << "Jump to: " << nextBlockTrue->getName() << std::endl;
    }
   
}

void BasicBlock::printAsm(std::ostream &os, AsmType asmType) const
{
    printAsmLabel(os, asmType);

    for(sh_AbsInstruction inst : instructionsList )
    {
        os << inst->toAsm(asmType) << std::endl;
    }

    printAsmJump(os,asmType);
}

std::string BasicBlock::getName() const
{
    return name;
}

void BasicBlock::setName(const std::string &value)
{
    name = value;
}

sh_BasicBlock BasicBlock::getNextBlockTrue() const
{
    return nextBlockTrue;
}

sh_BasicBlock BasicBlock::getNextBlockFalse() const
{
    return nextBlockFalse;
}

std::map<std::string, sh_Memory> BasicBlock::getUsedMemory() const
{
    return usedMemory;
}

std::list<sh_AbsInstruction> &BasicBlock::getInstructionsList()
{
    return instructionsList;
}

std::list<sh_BasicBlock> BasicBlock::getPreviousBlocks() const
{
    return previousBlocks;
}

bool BasicBlock::isConditionnal() const
{
    return nextBlockFalse != nullptr && nextBlockTrue != nullptr;
}

void BasicBlock::printAsmLabel(std::ostream &os, AsmType asmType) const
{
    switch (asmType) {
    case AsmType::X64Linux:
        os << name << ":" << std::endl;
        break;
    default:
        std::cerr << "ASM type not set " << std::endl;
        break;
    }
}

void BasicBlock::printAsmJump(std::ostream &os, AsmType asmType) const
{
    if(nextBlockFalse == nullptr && nextBlockTrue == nullptr)
    {
        //if none of the two posibility is set

    }
    //if only one is set, no need to check any things
    else if(nextBlockFalse != nullptr && nextBlockTrue == nullptr)
    {
        switch (asmType) {
        case AsmType::X64Linux:
            os << "\tjmp " << nextBlockFalse->getName() << std::endl;
            break;
        default:
            break;
        }
    }
    else if((nextBlockFalse == nullptr && nextBlockTrue != nullptr) || conditionnalJumpRegister == nullptr)
    {//if the only the nextblockTrue is set or if the conditionnalRegister is undeffined
        switch (asmType) {
        case AsmType::X64Linux:
            os << "\tjmp " << nextBlockTrue->getName() << std::endl;
            break;
        default:
            break;
        }
    }
    else
    {
        //else the two are set, need to do a conditionnal jump
        switch (asmType) {
        case AsmType::X64Linux:
            os << "\tcmpq\t$0, " << conditionnalJumpRegister->getASMname(AsmType::X64Linux) << std::endl;
            os << "\tjne " << nextBlockTrue->getName() << std::endl;
            os << "\tjmp " << nextBlockFalse->getName() << std::endl;
            break;
        default:
            break;
        }

    }
}

Flag BasicBlock::getBasicBlockFlag() const
{
    return basicBlockFlag;
}

void BasicBlock::setBasicBlockFlag(const Flag &value)
{
    basicBlockFlag = value;
}

sh_Register BasicBlock::getConditionnalJumpRegister() const
{
    return conditionnalJumpRegister;
}



