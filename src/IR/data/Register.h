#ifndef REGISTER_H
#define REGISTER_H

#include <memory>

#include "AbstractData.h"

namespace IR {
    class Register : public AbstractData
    {
    public:
        Register(Type type, std::string name);
    };

    typedef std::shared_ptr<Register> sh_Register;
}


#endif // REGISTER_H
