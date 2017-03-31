#ifndef IR_ABSTRACTINSTRUCTION_H
#define IR_ABSTRACTINSTRUCTION_H

#include <string>
#include <list>
#include <map>
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

        std::list<sh_Register> getReadRegisterList() const;
        std::list<sh_Register> getWroteRegisterList() const;
        std::list<sh_AbstractData> getReadMemoryList() const;
        std::list<sh_AbstractData> getWroteMemoryList() const;

        std::map<std::string, sh_Register> getAliveRegister() const;
        bool pushToAliveRegister(const sh_Register &reg);
        void clearAliveRegister();

    protected:
        std::list<sh_Register> readRegisterList;
        std::list<sh_Register> writtenRegisterList;

        std::list<sh_AbstractData> readMemoryList;
        std::list<sh_AbstractData> writtenMemoryList;

    private:
        std::map<std::string, sh_Register> aliveRegister;
    };

    typedef std::shared_ptr<AbstractInstruction> sh_AbsInstruction;
}

#endif // IR_ABSTRACTINSTRUCTION_H
