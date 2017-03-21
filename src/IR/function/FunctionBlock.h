#ifndef FUNCTIONBLOCK_H
#define FUNCTIONBLOCK_H

#include <memory>

#include "AbstractFunction.h"
#include "../basicBlock/BasicBlock.h"

namespace IR {
    class FunctionBlock : public AbstractFunction
    {
    public:
        FunctionBlock(std::string name);
    private:
        BasicBlock functionInit;
        BasicBlock functionCore;
        BasicBlock functionReturn;

    };
}

#endif // FUNCTIONBLOCK_H
