cmake_minimum_required(VERSION 3.6)
project(ds_2_seqlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ds_2_seqlist ${SOURCE_FILES})