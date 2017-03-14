#ifndef READFROMMEMORY_H
#define READFROMMEMORY_H

#include "AbstractMemoryAcess.h"

class ReadFromMemory : public AbstractMemoryAcess
{
public:
    ReadFromMemory(std::shared_ptr<Memory> from, std::shared_ptr<Register> to);

private:
    std::shared_ptr<Memory> source;
    std::shared_ptr<Register> destination;
};

#endif // READFROMMEMORY_H
