cmake_minimum_required(VERSION 3.20)
project(ABC)

set(CMAKE_CXX_STANDARD 11)

add_executable(ABC source/main.cpp source/classes/Food.cpp source/classes/Food.h source/headers/abc.h source/headers/Constants.h)
