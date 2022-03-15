cmake_minimum_required(VERSION 3.21)
project(EffectiveCpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(const_test)
add_executable(TextBlock const_test/TextBlock.cpp)

include_directories(non_local_static_test)
add_library(non_local_static_test SHARED non_local_static_test/FileSystem.cpp)
add_executable(Client non_local_static_test/Client.cpp)
target_link_libraries(Client non_local_static_test)
