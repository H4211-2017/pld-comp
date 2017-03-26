#ifndef SETVALUE_H
#define SETVALUE_H

#include "../data/Constant.h"
#include "AbstractInstruction.h"

namespace IR {
    class SetValue : public AbstractInstruction
    {
    public:
        SetValue(Constant constant, sh_Register destRegister);

        virtual std::string toLinuxX86() const;

    private:
        sh_Register dest;
        Constant value;
    };
}


#endif // SETVALUE_H
