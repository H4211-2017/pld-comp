#ifndef OperatorEquals_H
#define OperatorEquals_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorEquals : public AbstractOperator
    {
    public:
        OperatorEquals(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OperatorEquals_H
