cmake_minimum_required (VERSION 3.8)

add_library(dynarrayt dynarrayt.h dynarrayt.cpp)

set_property(TARGET dynarrayt PROPERTY CXX_STANDARD 17)