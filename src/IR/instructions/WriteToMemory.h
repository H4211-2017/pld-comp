#ifndef WRITETOMEMORY_H
#define WRITETOMEMORY_H

#include "AbstractMemoryAcess.h"

namespace IR {
    class WriteToMemory : public AbstractMemoryAcess
    {
    public:
        WriteToMemory(sh_Register from, sh_Memory to);
        WriteToMemory(char value, sh_Memory to);
        WriteToMemory(int value, sh_Memory to);
        WriteToMemory(long value, sh_Memory to);

        virtual std::string toString() const;
        virtual std::string toLinuxX64() const;

    private:
        sh_Register source;
        sh_Memory destination;
        int type;
        char charValue;
        int intValue;
        long longValue;

        static const int MEMORY_TYPE;
        static const int CHAR_TYPE;
        static const int INT_TYPE;
        static const int LONG_TYPE;
    };
}


#endif // WRITETOMEMORY_H
