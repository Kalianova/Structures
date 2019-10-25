cmake_minimum_required (VERSION 3.8)

add_library(longint longint.h longint.cpp)

set_property(TARGET longint PROPERTY CXX_STANDARD 17)