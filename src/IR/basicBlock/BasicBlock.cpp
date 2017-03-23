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
void BasicBlock::insertNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock)
{
    basicBlock->setNextBlockTrue(this->nextBlockFalse);
    basicBlock->setNextBlockFalse(nullptr);
    this->setNextBlockFalse(basicBlock);
}

/**
 * @brief BasicBlock::insertNextBlockTrue insert the given BasicBlock as next true block
 *        and set the old next true block as the given BasicBlock next true block.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::insertNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock)
{
    basicBlock->setNextBlockTrue(this->nextBlockFalse);
    basicBlock->setNextBlockFalse(nullptr);
    this->setNextBlockTrue(basicBlock);
}

/**
 * @brief BasicBlock::setNextBlockFalse insert the given BasicBlock as next false block discarding the old one.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::setNextBlockFalse(std::shared_ptr<BasicBlock> basicBlock)
{
    this->nextBlockFalse = basicBlock;
}

/**
 * @brief BasicBlock::setNextBlockTrue insert the given BasicBlock as next true block discarding the old one.
 * @param basicBlock the BasicBlock to insert.
 */
void BasicBlock::setNextBlockTrue(std::shared_ptr<BasicBlock> basicBlock)
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
    for(sh_Memory mem : instruction->getReadMemoryVector())
    {
        usedMemory[mem->getName()] = mem;
    }
    for(sh_Memory mem : instruction->getWroteMemoryVector())
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





