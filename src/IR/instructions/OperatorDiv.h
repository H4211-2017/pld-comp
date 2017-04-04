#ifndef OperatorDiv_H
#define OperatorDiv_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorDiv : public AbstractOperator
    {
    public:
        OperatorDiv(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OperatorDiv_H
