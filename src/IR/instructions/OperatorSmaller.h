#ifndef OperatorSmaller_H
#define OperatorSmaller_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorSmaller : public AbstractOperator
    {
    public:
        OperatorSmaller(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);

        virtual std::string toLinuxX86() const;
        virtual std::string toString() const;
    };
}


#endif // OperatorSmaller_H
