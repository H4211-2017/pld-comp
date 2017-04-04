#ifndef READARRAYVALUE_H
#define READARRAYVALUE_H

#include "AbstractInstruction.h"
#include "../data/Memory.h"
#include "../data/MemoryArray.h"

namespace IR {
    class ReadArrayValue : public AbstractInstruction
    {
    public:
        ReadArrayValue(sh_MemoryArray array, sh_Register caseNumber, sh_Register dest);

        virtual std::string toString() const;
        virtual std::string toLinuxX64() const;

    private:
        sh_MemoryArray arraySource;
        sh_Register caseNumberRegister;
        sh_Register destRegister;
    };
}

#endif // READARRAYVALUE_H
