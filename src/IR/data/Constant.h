#ifndef CONSTANT_H
#define CONSTANT_H

#include <memory>

#include "AbstractData.h"

namespace IR {
    class Constant : AbstractData
    {
    public:
        Constant(Type type, long value);

    protected:
        long dataValue;
    };

    typedef std::shared_ptr<Constant> sh_Constant;
}


#endif // CONSTANT_H
