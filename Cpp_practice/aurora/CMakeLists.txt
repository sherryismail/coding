# define project settings
cmake_minimum_required(VERSION 3.2) # version can be 3.2+
set(PROJECT_NAME aurora) # to name the folder
project(${PROJECT_NAME} LANGUAGES CXX VERSION 1.000)

include(CMakePrintHelpers) # cmake_print_variables()
set(CMAKE_CXX_STANDARD 20) # GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2 -march=native")
set(UNITTEST_ROOT_DIR ${CMAKE_SOURCE_DIR}) # when run cmake, this is set to cwd
set(UNITTEST_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

#build tests
add_subdirectory(src)
add_subdirectory(test)