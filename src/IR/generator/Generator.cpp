#include "Generator.h"
#include <string>

using namespace IR;


Generator::Generator()
{

}

/**
 * @brief Generator::getNewUnusedMemmory get a raw memory
 * @param memoryType type of the wanted memory (its size)
 * @return the new memory
 */
sh_Memory Generator::getNewUnusedMemmory(Type memoryType) const
{
    static unsigned memoryNumber = 0;
    std::string memoryName = "!m";
    memoryName.append(std::to_string(memoryNumber).c_str());
    memoryNumber++;
    sh_Memory newMemory = std::make_shared<Memory>(memoryType, memoryName);

    return newMemory;
}

/**
 * @brief Generator::readArrayCase read a case of an array into a given memory cell
 * @param array the array from whith the value will be read
 * @param index memory where the index of the array read will by read
 * @param dest the memory where the array value will be writen
 * @return the list of instruction making this operation
 */
std::list<sh_AbsInstruction> Generator::readArrayCase(sh_MemoryArray array, sh_Memory index, sh_Memory dest) const
{
    std::list<sh_AbsInstruction> instructionList;
    sh_Register indexRegister = getNewUnusedRegister(index->getType());
    sh_Register valueRegister = getNewUnusedRegister(dest->getType());
    //load Values in register
    instructionList.push_back( std::make_shared<ReadFromMemory>(index, indexRegister) );
    //read array to register
    instructionList.push_back( std::make_shared<ReadArrayValue>(array, indexRegister, valueRegister) );
    //write result to memory
    instructionList.push_back( std::make_shared<WriteToMemory>(valueRegister, dest));

    return instructionList;
}

/**
 * @brief Generator::readArrayCase read a case of an array into a given memory cell
 * @param array the array from whith the value willbe read
 * @param index the index of the array read
 * @param dest the memory where the array value will be written
 * @return the list of instruction making this operation
 */
std::list<sh_AbsInstruction> Generator::readArrayCase(sh_MemoryArray array, Constant index, sh_Memory dest) const
{
    std::list<sh_AbsInstruction> instructionList;
    sh_Register indexRegister = getNewUnusedRegister(index.getType());
    sh_Register valueRegister = getNewUnusedRegister(dest->getType());
    //load Values in register
    instructionList.push_back( std::make_shared<SetValue>(index, indexRegister) );
    //read array to register
    instructionList.push_back( std::make_shared<ReadArrayValue>(array, indexRegister, valueRegister) );
    //write result to memory
    instructionList.push_back( std::make_shared<WriteToMemory>(valueRegister, dest));

    return instructionList;
}

/**
 * @brief Generator::setValue set a constant value to a memory
 * @param value the constant value to wrote in memory
 * @param dest the memory where the value will be written
 * @return the list of instruction making this operation
 */
std::list<sh_AbsInstruction> Generator::setValue(Constant value, sh_Memory dest) const
{
    std::list<sh_AbsInstruction> instructionList;
    sh_Register valueRegister = getNewUnusedRegister(dest->getType());
    //load Values in register
    instructionList.push_back( std::make_shared<SetValue>(value, valueRegister) );
    //write result to memory
    instructionList.push_back( std::make_shared<WriteToMemory>(valueRegister, dest));

    return instructionList;
}

/**
 * @brief Generator::setValue copie to value of a memory to an other memory
 * @param value memory where the value can be found
 * @param dest the memory where the value will be written
 * @return the list of instruction making this operation
 */
std::list<sh_AbsInstruction> Generator::setValue(sh_Memory value, sh_Memory dest) const
{
    std::list<sh_AbsInstruction> instructionList;
    sh_Register valueRegister = getNewUnusedRegister(dest->getType());
    //load Values in register
    instructionList.push_back( std::make_shared<ReadFromMemory>(value, valueRegister) );
    //write result to memory
    instructionList.push_back( std::make_shared<WriteToMemory>(valueRegister, dest));

    return instructionList;
}

/**
 * @brief Generator::call call a function
 * @param function the function called
 * @param param the arguments of the function call
 * @return the list of instruction making this operation
 */
std::list<sh_AbsInstruction> Generator::call(std::shared_ptr<AbstractFunction> function, std::list<sh_AbstractData> param) const
{
    std::list<sh_AbsInstruction> instructionList;
    //add call instruction
    instructionList.push_back( std::make_shared<Call>(function, param) );

    return instructionList;
}

/**
 * @brief Generator::getNewUnusedRegister get a new raw register
 * @param registerType type of the wanted register (it size)
 * @return the new register
 */
sh_Register Generator::getNewUnusedRegister(Type registerType) const
{
    static unsigned registerNumber = 0;
    std::string registerName = "!r";
    registerName.append(std::to_string(registerNumber).c_str());
    registerNumber++;
    sh_Register newRegister = std::make_shared<Register>(registerType, registerName);

    return newRegister;
}























