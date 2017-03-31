#ifndef DECR_INCR_LEFT_EXPRESSION_H
#define DECR_INCR_LEFT_EXPRESSION_H

#include "AbstractExpression.h"
#include "Variable/Variable.h"

namespace AST {

class DecrIncrLeftExpression : public AbstractExpression
{

public:

    DecrIncrLeftExpression(std::shared_ptr<Variable> var, int valueOfIncrement);

    virtual ~DecrIncrLeftExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

    virtual void printTree(int tabulationNumber) const;

private:
    std::shared_ptr<Variable> var;
    int valueOfIncrement;

};

} /* namespace AST */

#endif //DECR_INCR_LEFT_EXPRESSION_H
