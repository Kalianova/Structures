cmake_minimum_required (VERSION 3.8)

add_library(matrixa matrixa.h matrixa.cpp)

set_property(TARGET matrixa PROPERTY CXX_STANDARD 17)