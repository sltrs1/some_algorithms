cmake_minimum_required(VERSION 3.5)

project(some_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(some_algorithms main.cpp timer_singleton.h timer_singleton.cpp fibonacci.h fibonacci.cpp euclid.h euclid.cpp)
