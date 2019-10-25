cmake_minimum_required (VERSION 3.8)

add_library(matrixl matrixl.h matrixl.cpp)

set_property(TARGET matrixl PROPERTY CXX_STANDARD 17)