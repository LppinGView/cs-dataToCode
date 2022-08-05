cmake_minimum_required(VERSION 3.23)
project(cs_dataToCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs_dataToCode
        main.cpp
        linear-list/linklist.cpp linear-list/linklist.h linear-list/sqlist.cpp linear-list/sqlist.h linear-list/dlinklist.cpp linear-list/dlinklist.h)
