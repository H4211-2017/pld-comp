#include <iostream>

#include "Value.h"


using namespace AST;

Value::Value()
    : type(Type::ERROR)
{
    value = 0;
}

Value::Value(Type type, long int value)
    : type(type)
{
    setValue(value);
}

std::pair<Type, long int> Value::getValue() const
{
    return std::pair<Type, long int>(type, value);
}

void Value::setValue(long int value) {
    switch (type) {
    case CHAR:
        this->value = (char) value;
        if (value != this->value)
        {
            std::cerr << "Value::setValue : Automatic cast from long to char" << std::endl;
        }
        break;
    case INT_32:
        this->value = (int) value;
        if (value != this->value)
        {
            std::cerr << "Value::setValue : Automatic cast from long to int" << std::endl;
        }
        break;
    case INT_64:
        this->value = value;
        break;
    default:
        break;
    }
}
