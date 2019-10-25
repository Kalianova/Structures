cmake_minimum_required (VERSION 3.8)

add_library(queuea queuea.h queuea.cpp)

set_property(TARGET queuea PROPERTY CXX_STANDARD 17)