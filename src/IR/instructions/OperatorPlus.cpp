#include "OperatorPlus.h"

using namespace IR;

OperatorPlus::OperatorPlus(sh_Register resultRegister,
                           sh_Register firstValueRegister,
                           sh_Register secondValueRegister):
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
