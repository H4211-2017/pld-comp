#ifndef OPERATOR_AND_H
#define OPERATOR_AND_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorAnd : public AbstractOperator
    {
    public:
        OperatorAnd(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATOR_AND_H
