#ifndef SETVALUE_H
#define SETVALUE_H

#include "../data/Constant.h"
#include "AbstractInstruction.h"

namespace IR {
    class SetValue : public AbstractInstruction
    {
    public:
        SetValue(Constant constant, sh_Register destRegister);
        ~SetValue();

        virtual std::string toString() const;
        virtual std::string toLinuxX64() const;

    private:
        sh_Register dest;
        Constant value;
    };
}


#endif // SETVALUE_H
