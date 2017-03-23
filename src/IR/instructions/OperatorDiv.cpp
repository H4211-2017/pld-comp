#include "OperatorDiv.h"

using namespace IR;

OperatorDiv::OperatorDiv(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
