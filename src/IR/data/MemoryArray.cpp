#include "MemoryArray.h"

using namespace IR;

MemoryArray::MemoryArray(Type type, std::string name, unsigned size):
    AbstractData(type, name),
    dataSize(size)
{

}
