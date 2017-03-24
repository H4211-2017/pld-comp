#ifndef ABSTRACTINSTRUCTION_H
#define ABSTRACTINSTRUCTION_H

#include "AbstractNode.h"

namespace AST {

class AbstractInstruction : public AbstractNode
{
public:
    AbstractInstruction(std::string name);
};
}

#endif // ABSTRACTINSTRUCTION_H
