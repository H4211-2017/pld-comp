#ifndef VARIABLE_H
#define VARIABLE_H

#include "config.h"

class Variable
{
public:
    Variable();

    long int evaluate() const;
    typeVar getTypeVar() const;



private:
    typeVar type;
    long int value;
};

#endif // VARIABLE_H
