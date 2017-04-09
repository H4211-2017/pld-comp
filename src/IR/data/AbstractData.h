#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <memory>
#include <string>

#include "../config/Enums.h"

namespace IR {

    enum Type{
        VOID  =0,
        CHAR  =2,
        INT_32=4,
        INT_64=8
    };

    class AbstractData
    {
    public:
        AbstractData(Type type, std::string name);

        virtual std::string getName() const;
        virtual Type getType() const;
        virtual int getSizeInMemory() const;

        virtual std::string getASMname(AsmType asmType) const;
        virtual std::string getX64name() const =0;

        virtual void incrementReadCount();
        virtual void decrementReadCount();
        virtual void incrementWriteCount();
        virtual void decrementWriteCount();
        virtual int getReadCount() const;
        virtual int getWriteCount() const;

    protected:
        Type dataType; // 1, 2 or 4 byte(s)
        std::string dataName;

        int readCount;
        int writeCount;
    };

    typedef std::shared_ptr<AbstractData> sh_AbstractData;
}


#endif // ABSTRACTDATA_H
