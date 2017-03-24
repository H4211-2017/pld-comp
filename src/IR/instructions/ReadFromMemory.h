#ifndef READFROMMEMORY_H
#define READFROMMEMORY_H

#include "AbstractMemoryAcess.h"

namespace IR {
    class ReadFromMemory : public AbstractMemoryAcess
    {
    public:
        ReadFromMemory(sh_Memory from, sh_Register to);

        virtual std::string toLinuxX86() const;

    private:
        sh_Memory source;
        sh_Register destination;
    };
}


#endif // READFROMMEMORY_H
