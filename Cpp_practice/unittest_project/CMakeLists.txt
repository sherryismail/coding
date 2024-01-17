
cmake_minimum_required(VERSION 3.12) # version can be different
project(unittest_project) #name of your project

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(LIBNAME "WTP")
set(TESTNAME "TestRunner")
project(unittest_project) 
add_subdirectory(src)

#build tests
project(${TESTNAME})

add_subdirectory(test)
enable_testing()
add_test(${TESTNAME} ${TESTNAME})



# cmake_minimum_required(VERSION 3.12) # version can be different
# project(unittest_project) #name of your project

# # GoogleTest requires at least C++14
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   # Specify the commit you depend on and update it regularly.
#   URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# # include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
# include_directories(src)
# add_subdirectory(src)
# add_subdirectory(test)
# add_subdirectory(googletest)
# include(GoogleTest)




# enable_testing()
# add_executable(
#   prime_test 
#   unit_test.cpp
#   ) # add this executable
# add_subdirectory(googletest) # add googletest subdirectory
# add_subdirectory(prime) # add googletest subdirectory
# target_link_libraries(
#   prime_test PUBLIC gtest gtest_main) # link google test to this executable
# include(CTest)
# gtest_discover_tests(example) # Runs GTest with CTest