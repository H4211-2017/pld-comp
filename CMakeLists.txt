cmake_minimum_required(VERSION 2.8)

project(pld-comp)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(
        GLOB_RECURSE
        source_files
        src/*.cpp
)
file(
        GLOB_RECURSE
        header_files
        src/*.h
)

include_directories(${CMAKE_SOURCE_DIR}/include/)

#find_library(BISONTAB libsomelib.a)
#add_library(bisontab STATIC lib/libbisontab.a)
#add_library(lexyy STATIC lib/liblexyy.a)

add_executable(${PROJECT_NAME} ${source_files} ${header_files} bin/flex/lex.yy.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libbisontab.a)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/liblexyy.a)
