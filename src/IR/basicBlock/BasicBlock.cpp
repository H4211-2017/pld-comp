#include <algorithm>
#include <iostream>

#include "BasicBlock.h"

using namespace IR;

BasicBlock::BasicBlock()
{
    static int basicBlockNumber = 0;
    name = "!bb";
    name.append( std::to_string(basicBlockNumber) );
    basicBlockNumber++;
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
    this->nextBlockFalse = basicBlock;
}

/**
 * @brief BasicBlock::setNextBlockTrue insert the given BasicBlock as next true block discarding the old one.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::setNextBlockTrue(sh_BasicBlock basicBlock)
{
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
    for(sh_AbstractData mem : instruction->getReadMemoryList())
    {
        usedMemory[mem->getName()] = mem;
    }
    for(sh_AbstractData mem : instruction->getWroteMemoryList())
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
        conditionnalJumpRegister = instruction->getWroteRegisterList().front();
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
    ///insert in the False next block
    if(nextBlockFalse != nullptr)
    {
        //insert in the list (do not check if not already in the list)
        nextBlockFalse->previousBlocks.push_back(this->shared_from_this());
    }
    ///insert in the True next block
    if(nextBlockTrue != nullptr)
    {
        //insert in the list (do not check if not already in the list)
        nextBlockTrue->previousBlocks.push_back(this->shared_from_this());
    }
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
    else if(nextBlockFalse != nullptr)
    {
        os << "Jump to: " << nextBlockFalse->getName() << std::endl;
    }
    else if(nextBlockTrue != nullptr)
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

std::map<std::string, sh_AbstractData> BasicBlock::getUsedMemory() const
{
    return usedMemory;
}

std::list<sh_AbsInstruction> BasicBlock::getInstructionsList() const
{
    return instructionsList;
}

std::list<sh_BasicBlock> BasicBlock::getPreviousBlocks() const
{
    return previousBlocks;
}



