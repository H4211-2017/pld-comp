#ifndef GENERATOR_H
#define GENERATOR_H

#include <memory>

#include "../data/Memory.h"
#include "../data/Register.h"

namespace IR {
    class Generator
    {
    public:
        Generator();

        std::shared_ptr<Memory> addition(std::shared_ptr<Memory> a, std::shared_ptr<Memory> b);

    protected:
    };
}


#endif // GENERATOR_H
