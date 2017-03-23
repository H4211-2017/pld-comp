#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <string>

namespace IR {
    enum Type{
        Char, Integer, Long
    };

    class AbstractData
    {
    public:
        AbstractData(Type type, std::string name);

        std::string getName() const;
        Type getType() const;

    protected:
        Type dataType; // 1, 2 or 4 byte(s)
        std::string dataName;
    };
}


#endif // ABSTRACTDATA_H
