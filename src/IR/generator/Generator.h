#ifndef GENERATOR_H
#define GENERATOR_H

#include "../instructions/OperatorPlus.h"

#include "../data/Memory.h"
#include "../data/Register.h"

#include <list>

#include "../instructions/OperatorBiggerOrEqual.h"
#include "../instructions/Call.h"
#include "../instructions/AbstractInstruction.h"
#include "../instructions/OperatorSmaller.h"
#include "../instructions/WriteToMemory.h"
#include "../instructions/AbstractOperator.h"
#include "../instructions/OperatorMult.h"
#include "../instructions/OperatorEquals.h"
#include "../instructions/ReadFromMemory.h"
#include "../instructions/OperatorDiv.h"
#include "../instructions/OperatorSmallerOrEqual.h"
#include "../instructions/OperatorModulus.h"
#include "../instructions/AbstractMemoryAcess.h"
#include "../instructions/OperatorMinus.h"
#include "../instructions/OperatorBigger.h"
#include "../instructions/OperatorPlus.h"

namespace IR {
    class Generator
    {
    public:
        Generator();

        sh_Memory getNewUnusedMemmory(Type memoryType) const;

        //to define every possible binary IR operation
        template<typename IrOperator>
        std::list<sh_AbsInstruction> binaryOperator(sh_Memory valueA, sh_Memory valueB, sh_Memory dest) const;

    protected:
        sh_Register getNewUnusedRegister(Type memoryType) const;

    private:

    };
}


#endif // GENERATOR_H
