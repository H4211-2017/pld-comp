#include <algorithm>
#include <iostream>

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

std::shared_ptr<const BasicBlock> FunctionBlock::getFunctionReturn() const
{
    return functionReturn;
}
