#include "DecrIncrOperator.h"

using namespace IR;

DecrIncrOperator::DecrIncrOperator(sh_Register resultRegister, sh_Register firstValueRegister, int valueOfIncrement, bool isBefore)
    : destination(resultRegister), firstValue(firstValueRegister), value(valueOfIncrement), isBef(isBefore)
{
    this->writtenRegisterList.push_back(resultRegister);

    firstValue->incrementReadCount();
    firstValue->incrementWriteCount();
    destination->incrementWriteCount();
}

DecrIncrOperator::~DecrIncrOperator()
{
    destination->decrementWriteCount();
    firstValue->decrementReadCount();
    firstValue->decrementWriteCount();
}

std::string DecrIncrOperator::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    switch(value)
    {
    case 1:
        if(isBef)
        {
			ret.append("++");
			ret.append(firstValue->getName() );
		}
		else
		{
			ret.append(firstValue->getName() );
			ret.append("++");
		}
        break;
    case -1:
        if(isBef)
        {
			ret.append("--");
			ret.append(firstValue->getName() );
		}
		else
		{
			ret.append(firstValue->getName() );
			ret.append("--");
		}
        break;
    default:
        std::cerr << "DecrIncrOperator::toString() : ERROR unknown op" << std::endl;
    }
    ret.append( this->firstValue->getName() );
    return ret;
}

std::string DecrIncrOperator::toLinuxX64() const
{
    std::string ret = "";
    std::string operate;
    switch(value)
    {
    case 1:
		operate = "incq";
        break;
    case -1:
		operate = "decq";
        break;
    default:
        std::cerr << "DecrIncrOperator::toString() : ERROR unknown op" << std::endl;
    }
    
    if(isBef)
    {
		ret.append("\n\t"+operate+"\t");
		ret.append(firstValue->getASMname(AsmType::X64Linux));
		ret.append("\n\tmovq\t"+firstValue->getASMname(AsmType::X64Linux)+","+ destination->getASMname(AsmType::X64Linux) );
	}
	else
	{
		ret.append("\n\tmovq\t"+firstValue->getASMname(AsmType::X64Linux)+","+ destination->getASMname(AsmType::X64Linux) );
		ret.append("\n\t"+operate+"\t");
		ret.append(firstValue->getASMname(AsmType::X64Linux));
	}
    
    return ret;
}

/* Code en sortie :
*/
