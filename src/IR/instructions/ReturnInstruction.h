#ifndef RETURNINSTRUCTION_H
#define RETURNINSTRUCTION_H

#include "AbstractInstruction.h"

namespace IR {
    class ReturnInstruction : public AbstractInstruction
    {
    public:
        ReturnInstruction(sh_Memory returnValue);

        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;

    private:
        sh_Memory returnedMemory;
    };
}


#endif // RETURNINSTRUCTION_H
