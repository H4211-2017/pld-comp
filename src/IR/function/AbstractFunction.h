#ifndef ABSTRACTFUNCTION_H
#define ABSTRACTFUNCTION_H

#include <string>
#include <list>

#include "../data/AbstractData.h"
#include "../data/Register.h"

namespace IR {
    class AbstractFunction
    {
    public:
        AbstractFunction(std::string name);

        std::string getFunctionName() const;

    protected:
        std::string functionName;
        std::list<sh_AbstractData> functionParam;
        sh_Register functionReturn;
    };
}


#endif // ABSTRACTFUNCTION_H
