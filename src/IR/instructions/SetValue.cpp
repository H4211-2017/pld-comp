#include "SetValue.h"

using namespace IR;

SetValue::SetValue(Constant constant, sh_Register destRegister):
    AbstractInstruction(),
    dest(destRegister),
    value(constant)
{
    this->writtenRegisterList.push_back(destRegister);
}

std::string SetValue::toString() const
{
    std::string ret = "";
    ret.append( std::to_string(value.getDataValue()) );
    ret.append( " -> " );
    ret.append( dest->getName() );
    return ret;
}

std::string SetValue::toLinuxX64() const
{

}