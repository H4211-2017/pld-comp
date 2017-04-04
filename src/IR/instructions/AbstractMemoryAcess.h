#ifndef ABSTRACTMEMORYACESS_H
#define ABSTRACTMEMORYACESS_H

#include <memory>

#include "AbstractInstruction.h"
#include "../data/Memory.h"
#include "../data/Register.h"

namespace IR {
    class AbstractMemoryAcess : public AbstractInstruction
    {
    public:
        AbstractMemoryAcess();
    };
}


#endif // ABSTRACTMEMORYACESS_H
