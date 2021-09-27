cmake_minimum_required(VERSION 3.15)
project(SingletonAssignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(SingletonAssignment main.cpp Grade.cpp Grade.h Student.cpp Student.h Logger.cpp Logger.h)