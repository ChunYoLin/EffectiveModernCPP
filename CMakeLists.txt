cmake_minimum_required (VERSION 3.5)
project (EffectiveCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(hello hello.cxx)
add_executable(rule1 rule1.cxx)
