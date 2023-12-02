cmake_minimum_required(VERSION 3.25)
project(AdventOfCodeCpp)
set(CMAKE_CXX_STANDARD 20)

add_executable(AdventOfCodeCpp src/day01/day01.cpp)

include_directories(src/util)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()