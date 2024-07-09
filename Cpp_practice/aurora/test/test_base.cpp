#include </home/sism/training/aurora/src/base.hpp>
#include <gtest/gtest.h>
namespace {
// To use a test fixture, derive a class from testing::Test.
class BaseTest : public testing::Test {
 protected:
  void SetUp() override  {}
  void TearDown() override {}
  public:
  BaseTest(){} 
};
TEST_F(BaseTest, valid_object)
{
    uint8_t cc[MSG_DEFAULT_SIZE] = {'5','6','7','8','9','a','b','c','d','e'};
    Base * base1 = new Base(0x7878,0x55,0x4A,PAYLOAD_SIZE, cc);
    EXPECT_EQ(PAYLOAD_SIZE, base1->getPayloadLength());
}
TEST_F(BaseTest, failing_test){
    EXPECT_TRUE(false);
}
} //namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}