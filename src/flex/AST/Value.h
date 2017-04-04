#ifndef VALUE_H
#define VALUE_H

#include <utility>
#include "../../../IR/data/AbstractData.h"

namespace AST {
    enum Type
    {
        CHAR,
        INT_32,
        INT_64,
        VOID,
        ERROR
    };
    typedef enum Type Type;

    class Value
    {

    public:
        Value();
        Value(Type type, long int value);

        void setValue(long int value);
        std::pair<Type, long int> getValue() const;
        
        IR::Type getIRType() const;

    private:
        Type type;
        long int value;
    };
}


#endif // VALUE_H
