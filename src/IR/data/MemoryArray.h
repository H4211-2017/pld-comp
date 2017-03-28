#ifndef MEMORYARRAY_H
#define MEMORYARRAY_H

#include <memory>

#include "AbstractData.h"

namespace IR {
    class MemoryArray : public AbstractData
    {
    public:
        MemoryArray(Type type, std::string name, unsigned size);

    protected:
        unsigned dataSize;
    };

    typedef std::shared_ptr<MemoryArray> sh_MemoryArray;
}


#endif // MEMORYARRAY_H
