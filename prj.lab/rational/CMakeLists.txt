cmake_minimum_required (VERSION 3.8)

add_library(rational rational.h rational.cpp)

set_property(TARGET rational PROPERTY CXX_STANDARD 17)