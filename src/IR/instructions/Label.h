#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "AbstractInstruction.h"

namespace IR {
    class Label : public AbstractInstruction
    {
    public:
        Label();
        std::string labelName;
        std::string getLabelName();
        void setLabelName(std::string name);
    };
}


#endif // LABEL_H




