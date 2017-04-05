#include "BreakInstruction.h"

using namespace IR;

BreakInstruction::BreakInstruction()
{

}

std::string BreakInstruction::toString() const
{
    return "";
}

std::string BreakInstruction::toLinuxX64() const
{
    return "\tnop";
}
