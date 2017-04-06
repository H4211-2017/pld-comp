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
        Call(std::shared_ptr<AbstractFunction> function, std::list<sh_AbstractData> parameters, sh_Register returnRegister);
        ~Call();

        virtual std::string toString() const;

        virtual std::string toLinuxX64() const;

    private:
        std::shared_ptr<AbstractFunction> calledFunction;
        std::list<sh_AbstractData> functionParam;
        sh_Register functionReturn;
    };
}


#endif // CALL_H
