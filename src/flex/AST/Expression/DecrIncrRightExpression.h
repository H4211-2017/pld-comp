#ifndef DECR_INCR_RIGHT_EXPRESSION_H
#define DECR_INCR_RIGHT_EXPRESSION_H

#include "AbstractExpression.h"
#include "Variable/Variable.h"

namespace AST {

class DecrIncrRightExpression : public AbstractExpression
{

public:

    DecrIncrRightExpression(std::shared_ptr<Variable> var, int valueOfIncrement);

    virtual ~DecrIncrRightExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

    virtual void printTree(int tabulationNumber) const;

private:
    std::shared_ptr<Variable> var;
    int valueOfIncrement;

};

} /* namespace AST */

#endif //DECR_INCR_RIGHT_EXPRESSION_H
