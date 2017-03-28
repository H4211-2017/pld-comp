#ifndef OPERATORPLUS_H
#define OPERATORPLUS_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorPlus : public AbstractOperator
    {
    public:
        OperatorPlus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);

        virtual std::string toString() const;

        virtual std::string toLinuxX86() const;
    };
}


#endif // OPERATORPLUS_H
