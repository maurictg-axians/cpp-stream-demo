cmake_minimum_required(VERSION 3.20)
project(stream)

set(CMAKE_CXX_STANDARD 14)

include_directories(block)

add_executable(stream
        block/block.cpp
        block/block.h
        main.cpp)
