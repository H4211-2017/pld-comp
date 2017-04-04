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
        AbstractFunction(std::string name, std::list<sh_AbstractData> param = std::list<sh_AbstractData>(), sh_Register returnRegister = nullptr);

        std::string getFunctionName() const;

    protected:
        std::string functionName;
        std::list<sh_AbstractData> functionParam;
        sh_Register functionReturn;
    };
}


#endif // ABSTRACTFUNCTION_H
