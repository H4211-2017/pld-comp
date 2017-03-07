#include "WriteToMemory.h"

const int WriteToMemory::MEMORY_TYPE = 0;
const int WriteToMemory::CHAR_TYPE   = 1;
const int WriteToMemory::INT_TYPE    = 2;
const int WriteToMemory::LONG_TYPE   = 3;

WriteToMemory::WriteToMemory(std::shared_ptr<Register> from, std::shared_ptr<Memory> to) : AbstractMemoryAcess(), destination(to), source(from), type(MEMORY_TYPE)
{

}

WriteToMemory::WriteToMemory(char value, std::shared_ptr<Memory> to) : AbstractMemoryAcess(), charValue(value), type(CHAR_TYPE)
{

}

WriteToMemory::WriteToMemory(int value, std::shared_ptr<Memory> to) : AbstractMemoryAcess(), intValue(value), type(INT_TYPE)
{

}

WriteToMemory::WriteToMemory(long value, std::shared_ptr<Memory> to) : AbstractMemoryAcess(), longValue(value), type(LONG_TYPE)
{

}
