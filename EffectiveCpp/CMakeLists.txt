cmake_minimum_required(VERSION 3.21)
project(EffectiveCpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(const_test)
add_executable(TextBlock const_test/TextBlock.cpp)