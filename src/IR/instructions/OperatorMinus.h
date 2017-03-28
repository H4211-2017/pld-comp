#ifndef OperatorMinus_H
#define OperatorMinus_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorMinus : public AbstractOperator
    {
    public:
        OperatorMinus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OperatorMinus_H
