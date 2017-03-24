#ifndef MAINBODY_H
#define MAINBODY_H

#include "AbstractNode.h"
#include "Block.h"
#include "ArgumentList.h"
#include "MainType.h"

namespace AST {
    class MainBody : public AbstractNode
    {
    public:
        MainBody(std::shared_ptr<MainType> mainType, std::shared_ptr<ArgumentList> mainArg, std::shared_ptr<Block> mainBlock);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;

    private:
        std::shared_ptr<MainType> mainType;
        std::shared_ptr<ArgumentList> mainArg;
        std::shared_ptr<Block> mainBlock;
    };
}


#endif // MAINBODY_H
