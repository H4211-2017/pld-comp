#ifndef MODULOEXPRESSION_H
#define MODULOEXPRESSION_H

#include "AbstractBinaryExpression.h"
namespace AST{
class ModuloExpression : public AbstractBinaryExpression
{
public:

    ModuloExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~ModuloExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};
}
#endif // MODULOEXPRESSION_H
