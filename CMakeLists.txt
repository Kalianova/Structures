cmake_minimum_required(VERSION 3.6)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_MODULE_PATH 
  ${CMAKE_MODULE_PATH} 
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake 
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/catch2 
  CACHE STRING "Modules for CMake" FORCE
)
project(kalianova_a_v)

include_directories(prj.lab prj.thirdparty)
add_subdirectory(prj.lab)
add_subdirectory(prj.test)

