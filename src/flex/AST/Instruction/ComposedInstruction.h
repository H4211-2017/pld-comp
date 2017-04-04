
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
    	
    	ComposedInstruction(std::string name);
    	
        /**
         * @brief ComposedInstruction
         * @param abstractExpression the first abstract expression of a composed instruction
         */
        ComposedInstruction(std::shared_ptr<AbstractExpression> abstractExpression);

        /**
         * @brief addExpression
         * @param expression to add expressions to a composed instruction
         */
        void addExpression(std::shared_ptr<AbstractExpression> expression);
        
        std::vector<std::shared_ptr<AbstractExpression>> getListExpr() const;

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
    private:
        std::vector<std::shared_ptr<AbstractExpression>> listExpressions;

    };
}


#endif // COMPOSEDINSTRUCTION_H
