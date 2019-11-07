cmake_minimum_required (VERSION 3.8)

add_library(dynarray dynarray.h dynarray.cpp)

set_property(TARGET dynarray PROPERTY CXX_STANDARD 17)