#include "SetValue.h"

using namespace IR;

SetValue::SetValue(Constant constant, sh_Register destRegister):
    AbstractInstruction(),
    dest(destRegister),
    value(constant)
{
    this->writtenRegisterList.push_back(destRegister);
    dest->incrementWriteCount();
}

SetValue::~SetValue()
{
    dest->decrementWriteCount();
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
    std::string ret = "";
    ret.append("\tmovq\t$");
    ret.append(std::to_string(this->value.getDataValue()));
    ret.append(", ");
    ret.append(this->dest->getASMname(AsmType::X64Linux));
//    ret.append("\t#\twrite count: ");
//    ret.append(std::to_string(dest->getWriteCount()));
//    ret.append("\tread count: ");
//    ret.append(std::to_string(dest->getReadCount()));
    return ret;
}
