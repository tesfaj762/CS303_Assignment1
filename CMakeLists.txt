cmake_minimum_required(VERSION 3.29.6)
project(CS_303_Assignment1)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS)


set(SOURCES main.cpp
        Array.h
        Array.tpp
        file_handling.cpp
        file_handling.h
        TestArray.cpp
        TestArray.h
)


add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

