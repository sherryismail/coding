# Build output setup
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
project(googletest-git NONE)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

################################
# Tests
################################
# Add test cpp file
add_executable(${TESTNAME} testgtest.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(${TESTNAME} gtest gtest_main)


# ######################
# set(BINARY ${CMAKE_PROJECT_NAME}_tst)
# file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)# its like add_executable(ExampleProject file1.cpp file1.h)
# set(SOURCES ${TEST_SOURCES})
# add_executable(${BINARY} ${TEST_SOURCES})
# add_test(NAME ${BINARY} COMMAND ${BINARY})#he compiled executable file is named ExampleProject_tst.
# target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
##################
# enable_testing()
# add_executable(
#   ../src/prime_test_complex.cpp
#   unit_test
#   ) # add this executable
# add_subdirectory(../googletest) # add googletest subdirectory
# target_link_libraries(
#   prime_test PUBLIC gtest gtest_main) # link google test to this executable
# include(CTest)
# gtest_discover_tests(example) # Runs GTest with CTest