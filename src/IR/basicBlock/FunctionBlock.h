#ifndef FUNCTIONBLOCK_H
#define FUNCTIONBLOCK_H

#include <memory>

#include "BasicBlock.h"

namespace IR {
    class FunctionBlock
    {
    public:
        FunctionBlock();
    private:
        BasicBlock functionInit;
        BasicBlock functionCore;
        BasicBlock functionReturn;

    };
}

#endif // FUNCTIONBLOCK_H
