#ifndef REGISTERPARAMETERS_H
#define REGISTERPARAMETERS_H

#include <memory>
#include "AbstractData.h"

namespace IR {
    class RegisterParameters
    {
    public:
        RegisterParameters();

    public:
        Type dataType; // 1, 2 or 4 byte(s)
        std::string dataName;
        std::string asm_registerName;

        int readCount;
        int writeCount;
    };

    typedef std::shared_ptr<RegisterParameters> sh_RegisterParameters;
}


#endif // REGISTERPARAMETERS_H
