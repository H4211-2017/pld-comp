#include "SetValue.h"

using namespace IR;

SetValue::SetValue(sh_Memory memory, Constant constant):
    AbstractInstruction(),
    dest(memory),
    value(constant)
{
    this->wroteMemoryVector.push_back(memory);
}
