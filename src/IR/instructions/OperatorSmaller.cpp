#include "OperatorSmaller.h"

using namespace IR;

OperatorSmaller::OperatorSmaller(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
