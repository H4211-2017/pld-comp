#include "AbstractInstruction.h"

using namespace IR;

AbstractInstruction::AbstractInstruction()
{

}

std::vector<sh_Register > AbstractInstruction::getReadRegisterVector() const
{
    return readRegisterVector;
}

std::vector<sh_Register > AbstractInstruction::getWroteRegisterVector() const
{
    return wroteRegisterVector;
}

std::vector<sh_AbstractData> AbstractInstruction::getReadMemoryVector() const
{
    return readMemoryVector;
}

std::vector<sh_AbstractData> AbstractInstruction::getWroteMemoryVector() const
{
    return wroteMemoryVector;
}

std::string AbstractInstruction::toAsm(int asmType) const
{
    std::string ret;
    switch (asmType) {
    case ASM_TYPE_X86_LINUX:
        ret = toLinuxX86();
        break;
    default:
        break;
    }
    return ret;
}
