# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.10)

# 项目信息
project (cppcase)

include_directories(template)

# 指定生成目标
add_executable(Cppcase
        main.cpp
        template/template.cpp
        others/well\ number.cpp
        threads/joinable.cpp
        threads/threads.cpp
        threads/cpp11.cpp
        stl/vector.cpp)