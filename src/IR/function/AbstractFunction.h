#ifndef ABSTRACTFUNCTION_H
#define ABSTRACTFUNCTION_H

#include <string>

namespace IR {
    class AbstractFunction
    {
    public:
        AbstractFunction(std::string name);

        std::string getFunctionName() const;

    private:
        std::string functionName;
    };
}


#endif // ABSTRACTFUNCTION_H
