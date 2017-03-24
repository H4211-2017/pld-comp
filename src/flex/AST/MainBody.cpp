#include "MainBody.h"

using namespace AST;

MainBody::MainBody(std::shared_ptr<MainType> mainType, std::shared_ptr<ArgumentList> mainArg, std::shared_ptr<Block> mainBlock)
    : AbstractNode("MainBody"), mainType(mainType), mainArg(mainArg), mainBlock(mainBlock)
{

}

void MainBody::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;

    mainType->printTree(tabulationNumber + 1);
    mainArg->printTree(tabulationNumber + 1);
    mainBlock->printTree(tabulationNumber + 1);
}

Value MainBody::evaluate() const
{
    // TODO
}

void MainBody::buildIR() const
{
    //TODO
}
