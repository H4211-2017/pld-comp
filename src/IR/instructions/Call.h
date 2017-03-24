#ifndef CALL_H
#define CALL_H

#include <memory>

#include "AbstractInstruction.h"
#include "../function/AbstractFunction.h"

namespace IR {
    class Call : public AbstractInstruction
    {
    public:
        Call(std::shared_ptr<AbstractFunction> function);

        virtual std::string toLinuxX86() const;

    private:
        std::shared_ptr<AbstractFunction> calledFunction;
    };
}


#endif // CALL_H
