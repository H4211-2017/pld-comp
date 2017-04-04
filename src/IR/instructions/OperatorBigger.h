#ifndef OperatorBigger_H
#define OperatorBigger_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBigger : public AbstractOperator
    {
    public:
        OperatorBigger(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX86() const;
        virtual std::string toString() const;
    };
}


#endif // OperatorBigger_H
