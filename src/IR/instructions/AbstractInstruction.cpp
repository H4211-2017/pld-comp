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

std::vector<sh_Memory > AbstractInstruction::getReadMemoryVector() const
{
    return readMemoryVector;
}

std::vector<sh_Memory > AbstractInstruction::getWroteMemoryVector() const
{
    return wroteMemoryVector;
}
