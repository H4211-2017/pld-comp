#ifndef READARRAYVALUE_H
#define READARRAYVALUE_H

#include "AbstractInstruction.h"
#include "../data/Memory.h"
#include "../data/MemoryArray.h"

namespace IR {
    class ReadArrayValue : AbstractInstruction
    {
    public:
        ReadArrayValue(sh_MemoryArray array, sh_Register caseNumber, sh_Register dest);

    private:
        sh_MemoryArray arraySource;
        sh_Register caseNumberRegister;
        sh_Register destRegister;
    };
}

#endif // READARRAYVALUE_H
