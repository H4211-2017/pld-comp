#ifndef IR_ABSTRACTINSTRUCTION_H
#define IR_ABSTRACTINSTRUCTION_H

#include <string>
#include <list>
#include <map>
#include <memory>

#include "../data/Register.h"
#include "../data/Memory.h"

namespace IR {

    enum AsmType{
        X86Linux,
        X86Win //no need to implement it yet
    };

    class AbstractInstruction
    {
    public:
        AbstractInstruction();

        virtual std::string toString() const =0;

        std::string toAsm(AsmType asmType) const;
        virtual std::string toLinuxX86() const =0;

        std::list<sh_Register> getReadRegisterList() const;
        std::list<sh_Register> getWroteRegisterList() const;
        std::list<sh_Memory> getReadMemoryList() const;
        std::list<sh_Memory> getWroteMemoryList() const;

        const std::map<std::__cxx11::string, sh_Register> &getAliveRegister() const;
        bool pushToAliveRegister(const sh_Register &reg);
        void clearAliveRegister();

    protected:
        std::list<sh_Register> readRegisterList;
        std::list<sh_Register> writtenRegisterList;

        std::list<sh_Memory> readMemoryList;
        std::list<sh_Memory> writtenMemoryList;

    private:
        std::map<std::string, sh_Register> aliveRegister;
    };

    typedef std::shared_ptr<AbstractInstruction> sh_AbsInstruction;
}

#endif // IR_ABSTRACTINSTRUCTION_H
