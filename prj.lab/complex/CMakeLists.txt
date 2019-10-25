cmake_minimum_required (VERSION 3.8)

add_library(complex complex.h complex.cpp)
set_property(TARGET complex PROPERTY CXX_STANDARD 11)