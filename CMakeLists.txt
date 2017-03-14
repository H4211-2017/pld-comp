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

#add_library(bisontab STATIC lib/libbisontab.a)
#add_library(lexyy STATIC lib/liblexyy.a)

add_executable(${PROJECT_NAME} ${source_files} ${header_files})

TARGET_LINK_LIBRARIES(pld-comp ${CMAKE_SOURCE_DIR}/libbisontab.a)
TARGET_LINK_LIBRARIES(pld-comp ${CMAKE_SOURCE_DIR}/liblexyy.a)
