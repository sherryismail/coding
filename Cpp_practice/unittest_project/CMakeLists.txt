# define project settings
cmake_minimum_required(VERSION 3.16) # version can be different

set(CMAKE_CXX_STANDARD 20) # GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2 -march=native")
set(PROJECT_NAME unittest_project)
project(${PROJECT_NAME} LANGUAGES CXX VERSION 1.000)
enable_testing()

#build tests
add_subdirectory(src)
add_subdirectory(test)
# add_subdirectory(googletest)
# include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>