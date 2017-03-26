#include "SetValue.h"

using namespace IR;

SetValue::SetValue(Constant constant, sh_Register destRegister):
    AbstractInstruction(),
    dest(destRegister),
    value(constant)
{
    this->wroteRegisterVector.push_back(destRegister);
}

std::string SetValue::toLinuxX86() const
{

}
