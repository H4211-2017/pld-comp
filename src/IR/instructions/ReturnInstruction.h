#ifndef IR_RETURNINSTRUCTION_H
#define IR_RETURNINSTRUCTION_H

#include "AbstractInstruction.h"

namespace IR {
    class ReturnInstruction : public AbstractInstruction
    {
    public:
        ReturnInstruction(sh_Register returnValue = nullptr);
        ~ReturnInstruction();

        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;

    private:
        sh_Register returnedRegister;
    };
}


#endif // RETURNINSTRUCTION_H
