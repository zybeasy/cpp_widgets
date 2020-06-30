cmake_minimum_required(VERSION 3.16)
project(cpp_widgets)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_widgets main.cpp time/time_widget.h time/time_widget.cpp)