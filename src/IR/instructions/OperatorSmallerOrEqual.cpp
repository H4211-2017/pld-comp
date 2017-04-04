#include "OperatorSmallerOrEqual.h"

using namespace IR;

OperatorSmallerOrEqual::OperatorSmallerOrEqual(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
