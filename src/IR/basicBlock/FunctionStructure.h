#ifndef FUNCTIONSTRUCTURE_H
#define FUNCTIONSTRUCTURE_H

#include <list>

#include "../function/FunctionBlock.h"

namespace IR {
    class FunctionStructure
    {
    public:
        FunctionStructure();

        void addFunction(std::shared_ptr<FunctionBlock> function);

        std::list<std::shared_ptr<FunctionBlock> > getFuntionList() const;

    private:
        std::list<std::shared_ptr<FunctionBlock>> funtionList;
    };
}


#endif // FUNCTIONSTRUCTURE_H
