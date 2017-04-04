#ifndef CONSTANT_H
#define CONSTANT_H

#include <memory>

#include "AbstractData.h"

namespace IR {
    class Constant : public AbstractData
    {
    public:
        Constant(Type type, long value);

        long getDataValue() const;

        virtual std::string getX86name() const;

    protected:
        long dataValue;
    };

    typedef std::shared_ptr<Constant> sh_Constant;
}


#endif // CONSTANT_H
