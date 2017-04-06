#ifndef ABSTRACTOPERATOR_H
#define ABSTRACTOPERATOR_H

#include <memory>

#include "AbstractInstruction.h"
#include "../data/Register.h"

namespace IR {
    class AbstractOperator : public AbstractInstruction
    {
    public:
        AbstractOperator(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual ~AbstractOperator();
    protected:
        sh_Register destination;
        sh_Register firstValue;
        sh_Register secondValue;
    };
}


#endif // ABSTRACTOPERATOR_H
