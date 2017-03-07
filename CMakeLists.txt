cmake_minimum_required(VERSION 2.8)

project(pld-comp)
add_executable(${PROJECT_NAME} "main.cpp" "IR/AbstractInstruction.cpp" "IR/AbstractMemoryAcess.cpp" "IR/data/AbstractData.cpp" "IR/data/Register.cpp" "IR/data/Memory.cpp" "IR/WriteToMemory.cpp" "IR/ReadFromMemory.cpp" "IR/AbstractOperator.cpp" "IR/OperatorPlus.cpp" "IR/OperatorMinus.cpp" "IR/OperatorMult.cpp" "IR/OperatorDiv.cpp" "IR/OperatorModulus.cpp")
