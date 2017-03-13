#ifndef WRITETOMEMORY_H
#define WRITETOMEMORY_H

#include "AbstractMemoryAcess.h"

class WriteToMemory : public AbstractMemoryAcess
{
public:
    WriteToMemory(std::shared_ptr<Register> from, std::shared_ptr<Memory> to);
    WriteToMemory(char value, std::shared_ptr<Memory> to);
    WriteToMemory(int value, std::shared_ptr<Memory> to);
    WriteToMemory(long value, std::shared_ptr<Memory> to);

private:
    std::shared_ptr<Register> source;
    std::shared_ptr<Memory> destination;
    int type;
    char charValue;
    int intValue;
    long longValue;

    static const int MEMORY_TYPE;
    static const int CHAR_TYPE;
    static const int INT_TYPE;
    static const int LONG_TYPE;
};

#endif // WRITETOMEMORY_H
