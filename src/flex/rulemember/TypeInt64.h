#ifndef TYPEINT64_H
#define TYPEINT64_H

#include "Variable.h"

using namespace std;

class TypeInt64 : public Variable
{
public:
    TypeInt64(long int val, string name);
};

#endif // TYPEINT64_H
