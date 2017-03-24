#include "ReadFromMemory.h"

using namespace IR;

ReadFromMemory::ReadFromMemory(sh_Memory from, sh_Register to)
{
    this->readMemoryVector.push_back(from);
    this->wroteRegisterVector.push_back(to);
}

std::string ReadFromMemory::toLinuxX86() const
{

}
