#include "Generator.h"
#include <string>

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

using namespace IR;


Generator::Generator()
{

}

sh_Memory Generator::getNewUnusedMemmory(Type memoryType) const
{
    static unsigned memoryNumber = 0;
    std::string memoryName = "!m";
    memoryName.append(std::to_string(memoryNumber).c_str());
    memoryNumber++;
    sh_Memory newMemory = std::make_shared<Memory>(memoryType, memoryName);

    return newMemory;
}

sh_Register Generator::getNewUnusedRegister(Type registerType) const
{
    static unsigned registerNumber = 0;
    std::string registerName = "!r";
    registerName.append(std::to_string(registerNumber).c_str());
    registerNumber++;
    sh_Register newRegister = std::make_shared<Register>(registerType, registerName);

    return newRegister;
}

std::list<sh_AbsInstruction> Generator::addition(sh_Memory valueA, sh_Memory valueB, sh_Memory dest) const
{
    std::list<sh_AbsInstruction> instructionList;
    sh_Register registerValueA = getNewUnusedRegister(valueA->getType());
    sh_Register registerValueB = getNewUnusedRegister(valueB->getType());
    sh_Register registerDest = getNewUnusedRegister(dest->getType());
    //load Values in register
    instructionList.push_back( std::make_shared<ReadFromMemory>(valueA, registerValueA) );
    instructionList.push_back( std::make_shared<ReadFromMemory>(valueB, registerValueB) );
    //make calculation
    instructionList.push_back( std::make_shared<OperatorPlus>(registerDest, registerValueA, registerValueB));
    //write result to memory
    instructionList.push_back( std::make_shared<WriteToMemory>(registerDest, dest));
}
