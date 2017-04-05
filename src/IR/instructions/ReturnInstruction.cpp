#include "ReturnInstruction.h"
#include "../config/config.h"

using namespace IR;

ReturnInstruction::ReturnInstruction(sh_Memory returnValue):
    returnedMemory(returnValue)
{
    this->getReadMemoryList().push_back(returnedMemory);
}

std::string ReturnInstruction::toLinuxX64() const
{
    std::string ret = "";
    if(returnedMemory != nullptr)
    {
        ret="\tmovq\t"; // movl ???
        ret.append(returnedMemory->getASMname(AsmType::X64Linux));
        ret.append(", %");
        ret.append(ASM_X64_FUNCTION_RETURN_REGISTER);
    }
    return ret;
}

std::string ReturnInstruction::toString() const
{

}


