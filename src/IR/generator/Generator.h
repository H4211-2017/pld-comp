#ifndef GENERATOR_H
#define GENERATOR_H

#include "../data/Memory.h"
#include "../data/Register.h"
#include "../data/MemoryArray.h"
#include "../data/Constant.h"

#include <list>

#include "../instructions/OperatorBiggerOrEqual.h"
#include "../instructions/ReadArrayValue.h"
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
#include "../instructions/SetValue.h"
#include "../instructions/OperatorBigger.h"
#include "../instructions/OperatorPlus.h"

namespace IR {
    class Generator
    {
    public:
        Generator();

        sh_Memory getNewUnusedMemmory(Type memoryType) const;

        std::list<sh_AbsInstruction> readArrayCase(sh_MemoryArray array, sh_Memory index, sh_Memory dest) const;
        std::list<sh_AbsInstruction> readArrayCase(sh_MemoryArray array, Constant index, sh_Memory dest) const;
        std::list<sh_AbsInstruction> setValue(Constant value, sh_Memory dest) const;
        std::list<sh_AbsInstruction> setValue(sh_Memory value, sh_Memory dest) const;
        std::list<sh_AbsInstruction> call(std::shared_ptr<AbstractFunction> function, std::list<sh_AbstractData> param) const;
        //to define every possible binary IR operation
        template<typename IrOperator>
        std::list<sh_AbsInstruction> binaryOperator(sh_Memory valueA, sh_Memory valueB, sh_Memory dest) const;

    protected:
        sh_Register getNewUnusedRegister(Type memoryType) const;

    private:

    };
}


#endif // GENERATOR_H
