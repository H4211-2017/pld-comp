#include "Generator.h"
#include <string>

using namespace IR;


Generator::Generator()
{

}

/**
 * @brief Generator::getNewUnusedMemmory get a raw memory
 * @param memoryType type of the wanted memory (it size)
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


template<typename IrOperator>
/**
 * @brief Generator::binaryOperator generate the IR instructions to perform the given binary operation on the given memory
 * @param valueA left operator' side value (memory where the value is)
 * @param valueB rigth operator' side value (memory where the value is)
 * @param dest memory where the result must be wrote
 * @return list of IR instructions performing the wanted operation
 */
std::list<sh_AbsInstruction> Generator::binaryOperator(sh_Memory valueA, sh_Memory valueB, sh_Memory dest) const
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
}
