cmake_minimum_required(VERSION 3.23)
project(cs_dataToCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs_dataToCode main.cpp linear-list/sqlist.h linear-list/sqlist.cpp)
