/* 
//Install Windows SDK, C++ compiler (https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/)
//Install cmake for Windows (https://cmake.org/download/)
cd unittest
git submodule add https://github.com/google/googletest.git googletest
mkdir build && cd build        # Create a directory to hold the build output.
cmake ..             # Generate native build scripts for GoogleTest.
A gtest.sln file and several .vcproj files will be created. You can then build them using Visual Studio.
git clean -d -f -x //to remove all files not under source control. This is if cmake .. produces files outside build/ directory
Install Make from (https://sourceforge.net/projects/gnuwin32/)
*/

#include "prime_test.hpp"
#include <gtest/gtest.h>
namespace {
// To use a test fixture, derive a class from testing::Test.
class PrimeNumberTest : public testing::Test {
 protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.
  // virtual void SetUp() will be called before each test is run.  You
  // should define it if you need to initialize the variables.
  // Otherwise, this can be skipped.
  PrimeNumberTest(){}
  void SetUp() override  {}
  void TearDown() override {}
};
TEST_F(PrimeNumberTest, valid_answers)
{
    int a[5] = {3,5,6,8,10};
    EXPECT_EQ(0,is_it_prime(a,5));
}
} //namespace
#define GOOGLETEST
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}