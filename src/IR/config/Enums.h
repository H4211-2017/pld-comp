#ifndef ENUMS_H
#define ENUMS_H


namespace IR {

    enum class AsmType
    {
        X64Linux,
        X64Win //no need to implement it yet
    };

    enum class OptimisationLevel{
        O0 = 0,
        O1 = 1,
        O2 = 2
    };
}

#endif // ENUMS_H
