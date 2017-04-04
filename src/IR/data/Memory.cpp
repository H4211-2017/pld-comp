#include "Memory.h"

using namespace IR;

Memory::Memory(Type type, std::string name):
    AbstractData(type,name)
{
    asm_basePointerOffset = 0;
}

int Memory::getAsmBasePointerOffset() const
{
    return asm_basePointerOffset;
}

void Memory::setAsmBasePointerOffset(int value)
{
    asm_basePointerOffset = value;
}

std::string Memory::getX64name() const
{
    std::string ret = "";
    ret.append( std::to_string(this->asm_basePointerOffset) );
    ret.append( "(%rbp)" );
    return ret;
}
