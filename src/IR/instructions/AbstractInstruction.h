#ifndef ABSTRACTINSTRUCTION_H
#define ABSTRACTINSTRUCTION_H

#include <string>
#include <vector>
#include <memory>

#include "../data/Register.h"
#include "../data/Memory.h"

namespace IR {
    const int ASM_TYPE_X86_LINUX = 1;
    const int ASM_TYPE_X86_WIN = 2; //no need to implement it yet

    class AbstractInstruction
    {
    public:
        AbstractInstruction();

        virtual std::string toString() const =0;

        std::string toAsm(int asmType) const;
        virtual std::string toLinuxX86() const =0;

        std::vector<sh_Register> getReadRegisterVector() const;
        std::vector<sh_Register> getWroteRegisterVector() const;
        std::vector<sh_AbstractData> getReadMemoryVector() const;
        std::vector<sh_AbstractData> getWroteMemoryVector() const;

    protected:
        std::vector<sh_Register> readRegisterVector;
        std::vector<sh_Register> wroteRegisterVector;

        std::vector<sh_AbstractData> readMemoryVector;
        std::vector<sh_AbstractData> wroteMemoryVector;
    };

    typedef std::shared_ptr<AbstractInstruction> sh_AbsInstruction;
}

#endif // ABSTRACTINSTRUCTION_H
