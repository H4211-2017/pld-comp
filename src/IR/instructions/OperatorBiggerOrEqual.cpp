#include "OperatorBiggerOrEqual.h"

using namespace IR;

OperatorBiggerOrEqual::OperatorBiggerOrEqual(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
