#ifndef OperatorBiggerOrEqual_H
#define OperatorBiggerOrEqual_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBiggerOrEqual : public AbstractOperator
    {
    public:
        OperatorBiggerOrEqual(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OperatorBiggerOrEqual_H
