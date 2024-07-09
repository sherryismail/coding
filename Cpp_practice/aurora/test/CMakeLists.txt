cmake_minimum_required(VERSION 3.16)
set(TSTS unittest_base)

# ################################
# # Configure-time download
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
set_source_files_properties(test_base.cpp PROPERTIES LANGUAGE CXX)
set_source_files_properties(test_film.cpp PROPERTIES LANGUAGE CXX)
################################
# Tests
################################
# Add path to source file here otherwise fatal error: No such file or directory
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${UNITTEST_ROOT_DIR}/src")
add_executable(${TSTS} test_base.cpp test_film.cpp)
target_link_libraries(${TSTS} PUBLIC ${LIBS} gtest gtest_main)

#############################################################################################
