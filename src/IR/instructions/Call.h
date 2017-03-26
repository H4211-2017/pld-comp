#ifndef CALL_H
#define CALL_H

#include <memory>
#include <list>

#include "AbstractInstruction.h"
#include "../function/AbstractFunction.h"
#include "../data/AbstractData.h"

namespace IR {
    class Call : public AbstractInstruction
    {
    public:
        Call(std::shared_ptr<AbstractFunction> function, std::list<sh_AbstractData> parameters);

        virtual std::string toLinuxX86() const;

    private:
        std::shared_ptr<AbstractFunction> calledFunction;
        std::list<sh_AbstractData> functionParam;
    };
}


#endif // CALL_H
