#include "Register.h"

using namespace IR;

Register::Register(Type type, std::string name):
    AbstractData(type,name)
{
    asm_registerName = "";
}

std::string Register::getAsmRegisterName() const
{
    return asm_registerName;
}

void Register::setAsmRegisterName(const std::string &value)
{
    asm_registerName = value;
}

std::string Register::getX86name() const
{
    std::string ret = "%";
    ret.append( this->asm_registerName );
    return ret;
}
