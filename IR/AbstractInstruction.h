#ifndef ABSTRACTINSTRUCTION_H
#define ABSTRACTINSTRUCTION_H

#include <string>

const int ASM_TYPE_X86_LINUX = 1;
const int ASM_TYPE_X86_WIN = 2; //no need to implement it yet

class AbstractInstruction
{
public:
    AbstractInstruction();

    virtual std::string toAsm(int asmType) =0;
    virtual std::string toLinuxX86() =0;
};

#endif // ABSTRACTINSTRUCTION_H
