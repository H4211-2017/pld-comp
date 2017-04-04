#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <memory>
#include <string>

#include "../config/Enums.h"

namespace IR {

    enum Type{
        CHAR  =1,
        INT_32=2,
        INT_64=4
    };

    class AbstractData
    {
    public:
        AbstractData(Type type, std::string name);

        std::string getName() const;
        Type getType() const;
        virtual int getSizeInMemory() const;

        virtual std::string getASMname(AsmType asmType) const;
        virtual std::string getX86name() const =0;

    protected:
        Type dataType; // 1, 2 or 4 byte(s)
        std::string dataName;
    };

    typedef std::shared_ptr<AbstractData> sh_AbstractData;
}


#endif // ABSTRACTDATA_H
