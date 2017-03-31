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

    /**
     * @brief Generator::binaryOperator generate the IR instructions to perform the given binary operation on the given memory
     * @param valueA left operator' side value (memory where the value is)
     * @param valueB rigth operator' side value (memory where the value is)
     * @param dest memory where the result must be wrote
     * @return list of IR instructions performing the wanted operation
     */
    template<typename IrOperator> std::list<sh_AbsInstruction> Generator::binaryOperator(sh_Memory valueA, sh_Memory valueB, sh_Memory dest) const
    {
        // Compile-time sanity check
        static_assert(std::is_base_of<AbstractOperator, IrOperator>::value, "Generator::binaryOperator Error: given Operator is not a subclass of AbstractOperator");
        std::list<sh_AbsInstruction> instructionList;
        sh_Register registerValueA = getNewUnusedRegister(valueA->getType());
        sh_Register registerValueB = getNewUnusedRegister(valueB->getType());
        sh_Register registerDest = getNewUnusedRegister(dest->getType());
        //load Values in register
        instructionList.push_back( std::make_shared<ReadFromMemory>(valueA, registerValueA) );
        instructionList.push_back( std::make_shared<ReadFromMemory>(valueB, registerValueB) );
        //make calculation
        instructionList.push_back( std::make_shared<IrOperator>(registerDest, registerValueA, registerValueB));
        //write result to memory
        instructionList.push_back( std::make_shared<WriteToMemory>(registerDest, dest));

        return instructionList;
    }

}


#endif // GENERATOR_H
