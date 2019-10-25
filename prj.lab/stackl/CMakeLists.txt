cmake_minimum_required (VERSION 3.8)

add_library(stackl stackl.h stackl.cpp)

set_property(TARGET stackl PROPERTY CXX_STANDARD 17)