cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


project(FunctionPointers)
add_executable(
    FunctionPointers
    function_pointers.cpp
)

