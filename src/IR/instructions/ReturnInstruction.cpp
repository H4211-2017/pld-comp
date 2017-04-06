#include "ReturnInstruction.h"
#include "../config/config.h"

using namespace IR;

ReturnInstruction::ReturnInstruction(sh_Register returnValue):
    returnedRegister(returnValue)
{
    if(returnedRegister != nullptr)
    {
        readRegisterList.push_back(returnedRegister);
        returnedRegister->incrementReadCount();
    }
}

ReturnInstruction::~ReturnInstruction()
{
    if(returnedRegister != nullptr)
    {
        returnedRegister->decrementReadCount();
    }
}

std::string ReturnInstruction::toLinuxX64() const
{
    std::string ret = "";
    if(returnedRegister != nullptr)
    {
        ret="\tmovq\t"; // movl ???
        ret.append(returnedRegister->getASMname(AsmType::X64Linux));
        ret.append(", %");
        ret.append(ASM_X64_FUNCTION_RETURN_REGISTER);
    }
    return ret;
}

std::string ReturnInstruction::toString() const
{
    std::string ret = "return ";
    if(this->returnedRegister != nullptr)
    {
        ret.append(this->returnedRegister->getName());
    }
    return ret;
}


