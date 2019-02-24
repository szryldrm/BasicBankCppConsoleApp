cmake_minimum_required(VERSION 3.6)
project(BankAssigent)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stack.cpp stack.h queue.cpp queue.h)
add_executable(BankAssigent ${SOURCE_FILES})