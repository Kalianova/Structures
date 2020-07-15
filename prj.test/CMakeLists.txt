cmake_minimum_required (VERSION 3.8)

add_subdirectory (test_complex)
add_subdirectory (test_rational)
add_subdirectory (test_longint)

add_subdirectory(catch2_complex)
add_subdirectory(catch2_dynarray)
add_subdirectory(catch2_rational)
add_subdirectory(catch2_matrixa)
add_subdirectory(catch2_stackl)