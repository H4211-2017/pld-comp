#ifndef EXTERNALFUNCTION_H
#define EXTERNALFUNCTION_H

#include "AbstractFunction.h"

namespace IR {
    class ExternalFunction : public AbstractFunction
    {
    public:
        ExternalFunction(std::string name, Type returnType, std::list<sh_AbstractData> param = std::list<sh_AbstractData>());

    };
}


#endif // EXTERNALFUNCTION_H
