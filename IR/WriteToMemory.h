#ifndef WRITETOMEMORY_H
#define WRITETOMEMORY_H

#include "AbstractMemoryAcess.h"

class WriteToMemory : public AbstractMemoryAcess
{
public:
    WriteToMemory(std::shared_ptr<Register> from, std::shared_ptr<Memory> to);

private:
    std::shared_ptr<Register> source;
    std::shared_ptr<Memory> destination;
};

#endif // WRITETOMEMORY_H
