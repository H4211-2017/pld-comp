#ifndef EXTERNALFUNCTION_H
#define EXTERNALFUNCTION_H

#include "AbstractFunction.h"

namespace IR {
    class ExternalFunction : public AbstractFunction
    {
    public:
        ExternalFunction(std::string name);
    };
}


#endif // EXTERNALFUNCTION_H
