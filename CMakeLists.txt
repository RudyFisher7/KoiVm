cmake_minimum_required(VERSION 3.13)
project(KoiVM VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")

add_library(${PROJECT_NAME} STATIC
    source/gate.cpp
    include/virtual_machine/gate.hpp
    source/full_adder.cpp
    include/virtual_machine/full_adder.hpp
    source/full_adder_circuit.cpp
    include/virtual_machine/full_adder_circuit.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

add_subdirectory(debug)
