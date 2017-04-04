#ifndef EXTERNALFUNCTION_H
#define EXTERNALFUNCTION_H

#include "AbstractFunction.h"

namespace IR {
    class ExternalFunction : public AbstractFunction
    {
    public:
        ExternalFunction(std::string name, std::list<sh_AbstractData> param = std::list<sh_AbstractData>(), sh_Register returnRegister = nullptr);

    };
}


#endif // EXTERNALFUNCTION_H
