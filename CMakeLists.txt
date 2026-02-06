cmake_minimum_required(VERSION 4.1)
project(1uzd)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    add_compile_options(/utf-8)
endif()
if (MINGW)
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

add_executable(1uzd main.cpp)
