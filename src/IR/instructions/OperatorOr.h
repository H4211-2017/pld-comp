#ifndef OPERATOR_OR_H
#define OPERATOR_OR_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorOr : public AbstractOperator
    {
    public:
        OperatorOr(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATOR_OR_H
