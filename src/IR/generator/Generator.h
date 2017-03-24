#ifndef GENERATOR_H
#define GENERATOR_H

#include "../instructions/OperatorPlus.h"

#include "../data/Memory.h"
#include "../data/Register.h"

#include <list>

namespace IR {
    class Generator
    {
    public:
        Generator();

        sh_Memory getNewUnusedMemmory(Type memoryType) const; ///TODO
        sh_Register getNewUnusedRegister(Type memoryType) const; ///TODO

        std::list<sh_AbsInstruction> addition(sh_Memory valueA, sh_Memory valueB, sh_Memory dest) const; ///TODO

    protected:

    private:

    };
}


#endif // GENERATOR_H
