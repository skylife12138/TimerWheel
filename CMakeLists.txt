# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

#项目名称, 参数值是 Demo1, 该命令表示项目的名称是 Demo1
project(TimerWheel)

# 指定生成目标
add_executable(TimerWheel main.cpp TimeWheel.cpp)
