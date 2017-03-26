#include <algorithm>

#include "BasicBlock.h"

using namespace IR;

BasicBlock::BasicBlock()
{

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
    for(sh_AbstractData mem : instruction->getReadMemoryVector())
    {
        usedMemory[mem->getName()] = mem;
    }
    for(sh_AbstractData mem : instruction->getWroteMemoryVector())
    {
        usedMemory[mem->getName()] = mem;
    }

    for(sh_Register reg : instruction->getReadRegisterVector())
    {
        usedRegister[reg->getName()] = reg;
    }
    for(sh_Register reg : instruction->getWroteRegisterVector())
    {
        usedRegister[reg->getName()] = reg;
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
 * @brief BasicBlock::setEndConditionnalInstruction set the instruction used to choose the next BasicBlock.
 * @param conditionalInstruction the instruction to use to choose.
 */
void BasicBlock::setEndConditionnalInstruction(sh_AbsInstruction conditionalInstruction)
{
    this->endConditionnalInstruction = conditionalInstruction;
}

/**
 * @brief BasicBlock::updateChildsPreviousBlock recursivelly update the previous block list
 * of every child of this block.
 * Compartement is unknow if called second time after a change in the basic block tree.
 * (must be call only once the basic block tree is finished)
 */
void BasicBlock::updateChildsPreviousBlock()
{
    ///insert in the False next block
    if(nextBlockFalse != nullptr)
    {
        //insert only if not already in the list
        std::list<sh_BasicBlock> & list = nextBlockFalse->previousBlocks;
        auto it = std::find(list.begin(), list.end(), this->shared_from_this());
        if(it == list.end())
        {
            list.push_back(this->shared_from_this());
            //recursive call to update the child child (in the if in order to handle loop)
            nextBlockFalse->updateChildsPreviousBlock();
        }
    }
    ///insert in the True next block
    if(nextBlockTrue != nullptr)
    {
        //insert only if not already in the list
        std::list<sh_BasicBlock> & list = nextBlockTrue->previousBlocks;
        auto it = std::find(list.begin(), list.end(), this->shared_from_this());
        if(it == list.end())
        {
            list.push_back(this->shared_from_this());
            //recursive call to update the child child (in the if in order to handle loop)
            nextBlockTrue->updateChildsPreviousBlock();
        }
    }
}



