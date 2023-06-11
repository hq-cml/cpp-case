cmake_minimum_required(VERSION 3.21)
project(chapter5)

set(CMAKE_CXX_STANDARD 11)

add_executable(chapter5 main.cpp LibMat.cpp LibMat.h NumSequence.cpp NumSequence.h)
