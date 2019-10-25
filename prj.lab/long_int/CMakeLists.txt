cmake_minimum_required (VERSION 3.8)

add_library(long_int long_int.h long_int.cpp)

set_property(TARGET long_int PROPERTY CXX_STANDARD 11)