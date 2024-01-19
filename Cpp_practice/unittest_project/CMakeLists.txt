# define project settings
cmake_minimum_required(VERSION 3.16) # version can be different
include(CMakePrintHelpers) # cmake_print_variables()
set(CMAKE_CXX_STANDARD 20) # GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2 -march=native")
set(PROJECT_NAME unittest_project)
set(UNITTEST_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(UNITTEST_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

project(${PROJECT_NAME} LANGUAGES CXX VERSION 1.000)
enable_testing()

#build tests
add_subdirectory(src)
add_subdirectory(test)