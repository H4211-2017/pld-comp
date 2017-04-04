#ifndef CASE_ARRAY_H
#define CASE_ARRAY_H

#include "Variable.h"
#include "Array.h"
#include "AbstractExpression.h"

namespace AST
{
	class CaseArray : public Variable
	{
	public:
        
        CaseArray(std::shared_ptr<Array> array, std::shared_ptr<AbstractExpression> index);
        virtual ~CaseArray();
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    protected:
        std::shared_ptr<AbstractExpression> index;
        std::shared_ptr<Array> array;
    };
}

#endif // CASE_ARRAY_H

