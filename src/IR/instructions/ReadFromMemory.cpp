#include "ReadFromMemory.h"

using namespace IR;

ReadFromMemory::ReadFromMemory(sh_Memory from, sh_Register to):
    AbstractMemoryAcess(),
    source(from),
    destination(to)
{
    this->readMemoryVector.push_back(from);
    this->writtenRegisterVector.push_back(to);
}

std::string ReadFromMemory::toString() const
{
    std::string ret = "";
    ret.append( source->getName() );
    ret.append( " -> " );
    ret.append( destination->getName() );
    return ret;
}

std::string ReadFromMemory::toLinuxX86() const
{

}
