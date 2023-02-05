/* 
https://medium.com/swlh/google-test-installation-guide-for-c-in-windows-for-visual-studio-code-2b2e66352456

This Github repo contains libraries for google test. You can download the version of your choice.
Download libgtest.a and libgtest_main.a libraries.
Copy both these files into lib of MingW (Ex : C:\Program Files\mingw-w64\x86_64–8.1.0-win32-seh-rt_v6-rev0\mingw64\lib)
Go to Google test downloaded repo, extract it and navigate to: googletest →include →gtest 
[ex C:\Users\Downloads\googletest-release-1.10.0\googletest-release-1.10.0\googletest\include\gtest]. 
Copy that whole gtest file and copy to the folder MingW\lib\gcc\x86_64-w64-mingw32\8.1.0\include.
*/

#include "prime_test.hpp"
#include <gtest/gtest.h>

// To use a test fixture, derive a class from testing::Test.
class PrimeNumberTest : public testing::Test {
 protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.
  // virtual void SetUp() will be called before each test is run.  You
  // should define it if you need to initialize the variables.
  // Otherwise, this can be skipped.
  void SetUp() {}
  void TearDown() {}
};

namespace {
TEST(PrimeNumberTest, valid_answers)
{
    int a[5] = {3,5,6,8,10};
    EXPECT_EQ(0,is_it_prime(a,5));
}
}