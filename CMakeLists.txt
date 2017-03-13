cmake_minimum_required(VERSION 2.8)

project(pld-comp)

file(

        GLOB_RECURSE

        source_files

        IR/data/*.cpp
        IR/data/*.h
        IR/instructions/*.cpp
        IR/instructions/*.h
        IR/basicBlock/*.cpp
        IR/basicBlock/*.h

        flex/src/AST/*
)

add_executable(${PROJECT_NAME} main.cpp ${source_files})
