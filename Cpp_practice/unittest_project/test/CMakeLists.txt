cmake_minimum_required(VERSION 3.16)
set(TSTS unittest_prime)

# ################################
# # Submodule method
# ################################
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        release-1.10.0
# )

# # For Windows: Prevent overriding the parent project's compiler/linker settings
# # hook and configure dependencies after googletest submodule is available
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
# set(BUILD_GTEST ON CACHE BOOL "" FORCE)
# # FetchContent_MakeAvailable(googletest)
# ################################
# # Tests
# ################################
# add_executable(${TSTS} test_prime.cpp)
# target_include_directories(${TSTS} ${LIB1} PUBLIC ${CMAKE_SOURCE_DIR}) # So files can discover library headers
# target_link_libraries(${TSTS} PUBLIC ${LIB1} gtest gtest_main pthread) # link executable to googletest CPP src code
# add_test(NAME prime COMMAND unittest_prime) # CMake recognizes its relationship to project commands
# # include(GoogleTest)
# gtest_discover_tests(${TSTS}) # registrating the test 

################################
# Development Package method
################################
# Locate gtest after the *.a are added to /usr/lib
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("~/training/coding/Cpp_practice/unittest_project/src/")
SET(CMAKE_CXX_FLAGS  "-DGOOGLE_TEST_ACTIVE")
add_executable(${TSTS} test_prime.cpp)

target_include_directories(${TSTS} PUBLIC /home/sism/training/coding/Cpp_practice/unittest_project/src)
target_link_libraries(${TSTS} PUBLIC ${LIB_PRIME} ${GTEST_LIBRARIES} pthread) # link executable to googletest