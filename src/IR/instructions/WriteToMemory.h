#ifndef WRITETOMEMORY_H
#define WRITETOMEMORY_H

#include "AbstractMemoryAcess.h"
#include "../data/Constant.h"

namespace IR {
    class WriteToMemory : public AbstractMemoryAcess
    {
    public:
        WriteToMemory(sh_Register from, sh_Memory to);
        ~WriteToMemory();

        virtual std::string toString() const;
        virtual std::string toLinuxX64() const;

    private:
        sh_Register source;
        sh_Memory destination;
    };
}


#endif // WRITETOMEMORY_H
