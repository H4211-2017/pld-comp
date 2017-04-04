#ifndef FUNCTIONSTRUCTURE_H
#define FUNCTIONSTRUCTURE_H

#include <list>
#include <ostream>

#include "../function/FunctionBlock.h"
#include "../config/Enums.h"

namespace IR {
    class FunctionStructure
    {
    public:
        FunctionStructure();

        void addFunction(std::shared_ptr<FunctionBlock> function);
        std::list<std::shared_ptr<FunctionBlock> > getFuntionList() const;

        void printASM(std::ostream &os, AsmType asmType);

    private:
        void printX86prolog(std::ostream &os);

        std::list<std::shared_ptr<FunctionBlock>> funtionList;
    };
}


#endif // FUNCTIONSTRUCTURE_H
