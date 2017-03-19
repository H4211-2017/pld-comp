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

#include_directories(${CMAKE_SOURCE_DIR}/include/)

#find_library(BISONTAB libsomelib.a)
#add_library(bisontab STATIC lib/libbisontab.a)
#add_library(lexyy STATIC lib/liblexyy.a)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(MyParser ${CMAKE_SOURCE_DIR}/src/flex/bison.ypp ${CMAKE_CURRENT_BINARY_DIR}/bison.tab.cpp
    COMPILE_FLAGS -vd
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/bison.tab.hpp)
FLEX_TARGET(MyScanner ${CMAKE_SOURCE_DIR}/src/flex/tokens.lex ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    ${source_files} ${header_files}
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)



#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libbisontab.a)
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/liblexyy.a)
