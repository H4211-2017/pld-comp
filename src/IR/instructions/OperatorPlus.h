#ifndef OPERATORPLUS_H
#define OPERATORPLUS_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorPlus : public AbstractOperator
    {
    public:
        OperatorPlus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OPERATORPLUS_H
