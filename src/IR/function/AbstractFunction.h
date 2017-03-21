#ifndef ABSTRACTFUNCTION_H
#define ABSTRACTFUNCTION_H

#include <string>

namespace IR {
    class AbstractFunction
    {
    public:
        AbstractFunction(std::string name);

    private:
        std::string functionName;
    };
}


#endif // ABSTRACTFUNCTION_H
