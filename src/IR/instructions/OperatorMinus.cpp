#include "OperatorMinus.h"

using namespace IR;

OperatorMinus::OperatorMinus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
