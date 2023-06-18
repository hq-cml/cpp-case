cmake_minimum_required(VERSION 3.21)
project(chapter6)

set(CMAKE_CXX_STANDARD 11)

add_executable(chapter6 main.cpp BinaryTree.cpp BinaryTree.h less_than.cpp less_than.h member_template.cpp member_template.h)
