#include "OperatorMult.h"

using namespace IR;

OperatorMult::OperatorMult(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
