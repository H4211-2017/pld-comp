#ifndef REGISTER_H
#define REGISTER_H

#include <memory>
#include<string>

#include "AbstractData.h"
#include "RegisterParameters.h"

namespace IR {
    class Register : public AbstractData
    {
    public:
        Register(Type type, std::string name);

        virtual std::string getName() const;
        virtual Type getType() const;
        virtual int getSizeInMemory() const;

        std::string getAsmRegisterName() const;
        void setAsmRegisterName(const std::string &value);

        virtual std::string getX64name() const;

        sh_RegisterParameters getParameters() const;
        void setParameters(sh_RegisterParameters &value);

        virtual void incrementReadCount();
        virtual void decrementReadCount();
        virtual void incrementWriteCount();
        virtual void decrementWriteCount();
        virtual int getReadCount() const;
        virtual int getWriteCount() const;

        bool operator ==(Register r) const;

    private:
        sh_RegisterParameters parameters;
    };

    typedef std::shared_ptr<Register> sh_Register;
}


#endif // REGISTER_H
