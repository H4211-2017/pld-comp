#include "Register.h"
#include "iostream"

using namespace IR;

Register::Register(Type type, std::string name):
    AbstractData(type,name)
{
    parameters = std::make_shared<RegisterParameters>();
    parameters->asm_registerName = "";
    parameters->dataName = this->dataName;
    parameters->dataType = this->dataType;
    parameters->readCount = this->readCount;
    parameters->writeCount = this->writeCount;
}

std::string Register::getName() const
{
    return parameters->dataName;
}

Type Register::getType() const
{
    return parameters->dataType;
}

int Register::getSizeInMemory() const
{
    return parameters->dataType;
}

std::string Register::getAsmRegisterName() const
{
    return parameters->asm_registerName;
}

void Register::setAsmRegisterName(const std::string &value)
{
    parameters->asm_registerName = value;
}

std::string Register::getX64name() const
{
    std::string ret = "%";
    ret.append( parameters->asm_registerName );
    return ret;
}

sh_RegisterParameters Register::getParameters() const
{
    return parameters;
}

void Register::setParameters(sh_RegisterParameters &value)
{
    value->readCount += getReadCount();
    value->writeCount += getWriteCount();
    parameters = value;
}

void Register::incrementReadCount()
{
    parameters->readCount++;
}

void Register::decrementReadCount()
{
    parameters->readCount--;
}

void Register::incrementWriteCount()
{
    parameters->writeCount++;
}

void Register::decrementWriteCount()
{
    parameters->writeCount--;
}

int Register::getReadCount() const
{
    return parameters->readCount;
}

int Register::getWriteCount() const
{
    return parameters->writeCount;
}

bool Register::operator ==(Register r) const
{
    return this->parameters == r.parameters;
}
