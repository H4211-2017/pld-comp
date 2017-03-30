#include "WriteToMemory.h"

using namespace IR;

const int WriteToMemory::MEMORY_TYPE = 0;
const int WriteToMemory::CHAR_TYPE   = 1;
const int WriteToMemory::INT_TYPE    = 2;
const int WriteToMemory::LONG_TYPE   = 3;

WriteToMemory::WriteToMemory(sh_Register from, sh_Memory to) :
    AbstractMemoryAcess(), destination(to), source(from), type(MEMORY_TYPE)
{
    this->readRegisterList.push_back(from);
    this->writtenMemoryList.push_back(to);
}

WriteToMemory::WriteToMemory(char value, sh_Memory to) : AbstractMemoryAcess(), charValue(value), type(CHAR_TYPE)
{

}

WriteToMemory::WriteToMemory(int value, sh_Memory to) : AbstractMemoryAcess(), intValue(value), type(INT_TYPE)
{

}

WriteToMemory::WriteToMemory(long value, sh_Memory to) : AbstractMemoryAcess(), longValue(value), type(LONG_TYPE)
{

}

std::__cxx11::string WriteToMemory::toString() const
{
    std::string ret = "";
    ret.append( source->getName() );
    ret.append( " -> " );
    ret.append( destination->getName() );
    return ret;
}

std::string WriteToMemory::toLinuxX86() const
{

}
