#ifndef INCLUDE_COMMUN_H
#define INCLUDE_COMMUN_H

#include "AbstractNode.h"
#include "Block.h"
#include "Scope.h"
#include "Value.h"
#include "ProgramNode.h"

#include "Expression/AbstractExpression.h"
#include "Expression/Constant.h"
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
#include "Expression/AndExpression.h"
#include "Expression/DivExpression.h"
#include "Expression/EqExpression.h"
#include "Expression/IneqExpression.h"
#include "Expression/InfEqExpression.h"
#include "Expression/InfExpression.h"
#include "Expression/MultExpression.h"
#include "Expression/OrExpression.h"
#include "Expression/SubExpression.h"
#include "Expression/SupEqExpression.h"
#include "Expression/SupExpression.h"
#include "Expression/DecrIncrRightExpression.h"
#include "Expression/DecrIncrLeftExpression.h"

#include "Instruction/ComposedInstruction.h"
#include "Instruction/UnitInstruction.h"
#include "Instruction/SequenceInstruction.h"
#include "Instruction/ReturnInstruction.h"

#include "Variable/VariableSignature.h"
#include "Variable/VariableDeclaration.h"
#include "Variable/Variable.h"
#include "Variable/Array.h"
#include "Variable/ArrayDeclaration.h"
#include "Variable/CaseArray.h"

#include "Function/FunctionSignature.h"
#include "Function/LArguments.h"
#include "Function/Function.h"
#include "Function/FunctionDeclaration.h"
#include "Function/LParametres.h"
#include "Function/FunctionCall.h"

#include "Structure/AbstractStructure.h"
#include "Structure/IfStructure.h"
#include "Structure/ElseStructure.h"
#include "Structure/ForStructure.h"
#include "Structure/WhileStructure.h"

#endif
