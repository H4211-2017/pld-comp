#ifndef OperatorBigger_H
#define OperatorBigger_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBigger : public AbstractOperator
    {
    public:
        OperatorBigger(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OperatorBigger_H
