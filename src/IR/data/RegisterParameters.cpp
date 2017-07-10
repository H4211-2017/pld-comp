#include "RegisterParameters.h"

using namespace IR;

RegisterParameters::RegisterParameters()
{
    dataName = "";
    asm_registerName = "";
    readCount = 0;
    writeCount = 0;
    dataType = Type::INT_64;
}
