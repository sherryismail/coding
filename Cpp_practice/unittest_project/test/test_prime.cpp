#include <prime.hpp>
#include <gtest/gtest.h>
namespace Testing{
// To use a test fixture, derive a class from testing::Test.
class PrimeNumberTest : public testing::Test {
 protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.
  // virtual void SetUp() will be called before each test is run.  You
  // should define it if you need to initialize the variables.
  // Otherwise, this can be skipped.
  void SetUp() override  {}
  void TearDown() override {}
  public:
  PrimeNumberTest(){} 
};
TEST_F(PrimeNumberTest, valid_answers)
{
    int a[5] = {3,5,6,8,10};
    EXPECT_EQ(0,is_it_prime(a,5));
}
TEST_F(PrimeNumberTest, always_true)
{
    EXPECT_EQ(1, 1);
}
TEST_F(PrimeNumberTest, failing_test){
    EXPECT_TRUE(false);
}
} //namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}