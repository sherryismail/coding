cmake_minimum_required(VERSION 3.16)
set(TSTS unittest_prime)

################################
# Development Package method
################################
# Locate gtest after the *.a are added to /usr/lib
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add new header paths here
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${UNITTEST_ROOT_DIR}/src -DGOOGLE_TEST_ACTIVE -std=gnu++11")

# Add a new test file here
add_executable(${TSTS} test_prime.cpp)
target_link_libraries(${TSTS} PUBLIC ${LIBS} ${GTEST_LIBRARIES} pthread) # link executable to googletest

# Multiple directories handler
# target_include_directories(${TSTS} PUBLIC $<BUILD_INTERFACE:${UNITTEST_ROOT_DIR}/src;${UNITTEST_BUILD_DIR}/src>)