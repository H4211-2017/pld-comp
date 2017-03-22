#ifndef COMPOSEDINSTRUCTION_H
#define COMPOSEDINSTRUCTION_H

#include <vector>

#include "AbstractNode.h"
#include "AbstractExpression.h"

namespace AST {
    class ComposedInstruction : AbstractNode
    {
    public:
        ComposedInstruction(std::shared_ptr<ComposedInstruction> composedInstruction, std::shared_ptr<AbstractExpression> abstractExpression);
        ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression);

    private:
        std::vector<std::shared_ptr<AbstractExpression>> listExpressions;

    };
}


#endif // COMPOSEDINSTRUCTION_H
