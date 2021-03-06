#ifndef MEMORY_H
#define MEMORY_H

#include <memory>

#include "AbstractData.h"

namespace IR {
    class Memory : public AbstractData
    {
    public:
        Memory(Type type, std::string name);

        int getAsmBasePointerOffset() const;
        void setAsmBasePointerOffset(int value);

        virtual std::string getX64name() const;

    private:
        int asm_basePointerOffset;

    };

    typedef std::shared_ptr<Memory> sh_Memory;
}


#endif // MEMORY_H
