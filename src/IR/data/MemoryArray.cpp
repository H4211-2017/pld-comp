#include "MemoryArray.h"

using namespace IR;

MemoryArray::MemoryArray(Type type, std::string name, unsigned size):
    Memory(type, name),
    dataSize(size)
{

}

int MemoryArray::getSizeInMemory() const
{
    return dataType * dataSize;
}
