cmake_minimum_required(VERSION 3.20)
project(ABC)

set(CMAKE_CXX_STANDARD 11)

add_executable(ABC main.cpp classes/Food.cpp classes/Food.h abc.h classes/Constants.h)
