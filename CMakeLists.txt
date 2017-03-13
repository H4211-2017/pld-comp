cmake_minimum_required(VERSION 2.8)

project(pld-comp)

file(

        GLOB_RECURSE

        source_files

        IR/data/*
        IR/instructions/*
        IR/basicBlock/*
        flex/src/AST/*
)

add_executable(${PROJECT_NAME} "main.cpp" ${source_files})
