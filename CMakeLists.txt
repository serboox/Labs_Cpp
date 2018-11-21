cmake_minimum_required(VERSION 3.11)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

# which compilers to use for C and C++
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)

add_executable(lab5 main.cpp other.cpp)