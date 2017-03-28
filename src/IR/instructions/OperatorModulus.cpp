#include "OperatorModulus.h"

using namespace IR;

OperatorModulus::OperatorModulus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
