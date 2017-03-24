#ifndef SETVALUE_H
#define SETVALUE_H

#include "../data/Constant.h"
#include "AbstractInstruction.h"

namespace IR {
    class SetValue : AbstractInstruction
    {
    public:
        SetValue(sh_Memory memory, Constant constant);

    private:
        sh_Memory dest;
        Constant value;
    };
}


#endif // SETVALUE_H
