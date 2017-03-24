
#ifndef COMPOSEDINSTRUCTION_H
#define COMPOSEDINSTRUCTION_H

#include <vector>

#include "AbstractInstruction.h"
#include "AbstractExpression.h"

namespace AST {
    class ComposedInstruction : public AbstractInstruction
    {
    public:
    
    	ComposedInstruction();
    	
        ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression);

        void addExpression(std::shared_ptr<AbstractExpression> expression);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
    private:
        std::vector<std::shared_ptr<AbstractExpression>> listExpressions;

    };
}


#endif // COMPOSEDINSTRUCTION_H