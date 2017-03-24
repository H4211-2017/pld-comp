#include "Variable.h"

using namespace AST;

Variable::Variable(std::string identifiant, std::shared_ptr<VariableScope> variableScope)
    : AbstractExpression("Variable", variableScope->findVariable(identifiant)->getValue().getValue().first)
{

}
