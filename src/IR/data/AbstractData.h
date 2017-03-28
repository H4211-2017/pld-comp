#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <memory>
#include <string>

namespace IR {
    enum Type{
        CHAR, INT_32, INT_64
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

    typedef std::shared_ptr<AbstractData> sh_AbstractData;
}


#endif // ABSTRACTDATA_H
