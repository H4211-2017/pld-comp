#ifndef GENERATOR_H
#define GENERATOR_H

#include "../instructions/OperatorPlus.h"

#include "../data/Memory.h"
#include "../data/Register.h"

namespace IR {
    class Generator
    {
    public:
        Generator();

        sh_Memory getNewUnusedMemmory(); ///TODO

        std::list<sh_AbsInstruction> addition(sh_Memory valueA, sh_Memory valueB, sh_Memory dest); ///TODO

    protected:

    private:

    };
}


#endif // GENERATOR_H
