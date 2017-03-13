#ifndef JUMP_H
#define JUMP_H

#include <memory>

#include "AbstractInstruction.h"
#include "Label.h"

class Jump : public AbstractInstruction
{
public:
    Jump();
private:
    std::shared_ptr<Label> destination;
};

#endif // JUMP_H




