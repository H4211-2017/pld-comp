#ifndef BREAKINSTRUCTION_H
#define BREAKINSTRUCTION_H

#include "AbstractInstruction.h"

namespace IR {
    class BreakInstruction: public AbstractInstruction
    {
    public:
        BreakInstruction();

        virtual std::string toString() const;
        virtual std::string toLinuxX64() const;
    };
}


#endif // BREAKINSTRUCTION_H
