cmake_minimum_required(VERSION 3.16)
set(TSTS unittest_prime)

# ################################
# # Development Package method
# ################################
# # Follow the steps in README to install libgtest-dev 
# # Locate gtest after the *.a are added to /usr/lib and /usr/local/lib
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# ###############################
# # Tests
# ###############################
# # Add new header paths here
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${UNITTEST_ROOT_DIR}/src -DGOOGLE_TEST_ACTIVE -std=gnu++11")

# # Add a new test file here
# add_executable(${TSTS} test_prime.cpp)
# target_link_libraries(${TSTS} PUBLIC ${LIBS} ${GTEST_LIBRARIES} pthread) # link executable to googletest

# Multiple directories handler
# target_include_directories(${TSTS} PUBLIC $<BUILD_INTERFACE:${UNITTEST_ROOT_DIR}/src;${UNITTEST_BUILD_DIR}/src>)

#############################################################################################

# ################################
# # Configure-time download (instead of build time)
# ################################
find_package(Threads)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) # builds libgmock.a 
set(BUILD_GTEST ON CACHE BOOL "" FORCE) # builds libgtest.a
FetchContent_MakeAvailable(googletest)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGOOGLE_TEST_ACTIVE -std=gnu++11")
enable_testing()
# the below line is to fix the error: undefined reference to `testing::Test::Test()'
set_source_files_properties(test_prime.cpp PROPERTIES LANGUAGE CXX)
################################
# Tests
################################
# Add path to source file here otherwise fatal error: No such file or directory
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${UNITTEST_ROOT_DIR}/src")
add_executable(${TSTS} test_prime.cpp)
target_link_libraries(${TSTS} PUBLIC ${LIBS} gtest gtest_main)

#############################################################################################

# ################################
# # Submodule method (Not recommended)
# ################################
# > git submodule add https://github.com/google/googletest.git
# > git submodule update --init --recursive
# hook and configure dependencies after googletest submodule is available
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# add_subdirectory(googletest EXCLUDE_FROM_ALL)
# > git submodule deinit -f path/to/submodule # Remove the entry from .git/config
# > rm -rf .git/modules/path/to/submodule # Remove the dir from the superproject's .git/modules
# > git rm -f path/to/submodule # Remove the entry in .gitmodules and the dir located at path/to/submodule