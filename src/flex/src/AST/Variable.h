#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

class Variable
{
public:
    Variable();

    long int evaluate() const =0;


protected:
    long int value;

private:
    std::string id;
};

#endif // VARIABLE_H
