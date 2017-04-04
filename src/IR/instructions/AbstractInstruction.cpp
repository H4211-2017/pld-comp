#include "AbstractInstruction.h"

using namespace IR;

AbstractInstruction::AbstractInstruction()
{

}

std::list<sh_Register > AbstractInstruction::getReadRegisterList() const
{
    return readRegisterList;
}

std::list<sh_Register > AbstractInstruction::getWroteRegisterList() const
{
    return writtenRegisterList;
}

std::list<sh_Memory> AbstractInstruction::getReadMemoryList() const
{
    return readMemoryList;
}

std::list<sh_Memory> AbstractInstruction::getWroteMemoryList() const
{
    return writtenMemoryList;
}

const std::map<std::string, sh_Register> & AbstractInstruction::getAliveRegister() const
{
    return aliveRegister;
}

/**
 * @brief AbstractInstruction::pushToAliveRegister add the given register to the alive list if needed
 * @param reg the register to add
 * @return true if the register is added and false if the register was already on the list (map)
 */
bool AbstractInstruction::pushToAliveRegister(const sh_Register &reg)
{
    if(aliveRegister.find(reg->getName()) == aliveRegister.end())
    {
        aliveRegister[reg->getName()] = reg;
        return true;
    }
    else
    {
        return false;
    }
}

void AbstractInstruction::clearAliveRegister()
{
    aliveRegister.clear();
}

std::string AbstractInstruction::toAsm(AsmType asmType) const
{
    std::string ret;
    switch (asmType) {
    case AsmType::X64Linux:
        ret = toLinuxX64();
        break;
    default:
        break;
    }
    return ret;
}
