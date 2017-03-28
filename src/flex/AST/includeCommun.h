#ifndef INCLUDE_COMMUN_H
#define INCLUDE_COMMUN_H

#include "AbstractNode.h"
#include "Block.h"
#include "Scope.h"
#include "Value.h"

#include "Expression/Constant.h"
#include "Expression/AbstractExpression.h"
#include "Expression/UnaryExpression.h"
#include "Expression/AddExpression.h"
#include "Expression/IDExpression.h"
#include "Expression/AffectationExpression.h"
#include "Expression/ParenthesisExpression.h"
#include "Expression/BitwiseAndExpression.h"
#include "Expression/BitwiseOrExpression.h"
#include "Expression/BitwiseShiftLeftExpression.h"
#include "Expression/BitwiseXorExpression.h"
#include "Expression/ModuloExpression.h"
#include "AndExpression.h"
#include "DivExpression.h"
#include "EqExpression.h"
#include "IneqExpression.h"
#include "InfEqExpression.h"
#include "InfExpression.h"
#include "MultExpression.h"
#include "OrExpression.h"
#include "SubExpression.h"
#include "SupEqExpression.h"
#include "SupExpression.h"

#include "Instruction/ComposedInstruction.h"
#include "Instruction/UnitInstruction.h"
#include "Instruction/SequenceInstruction.h"

#include "Variable/VariableSignature.h"
#include "Variable/VariableDeclaration.h"
#include "Variable/Variable.h"

#include "Function/FunctionSignature.h"
#include "Function/LArguments.h"
#include "Function/Function.h"
#include "Function/FunctionDeclaration.h"
#include "Function/LParametres.h"
#include "Function/FunctionCall.h"

#include "Structure/AbstractStructure.h"
#include "Structure/IfStructure.h"
#include "Structure/ElseStructure.h"

#endif
