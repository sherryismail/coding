#include </home/sism/training/aurora/src/base.hpp>
#include <gtest/gtest.h>
namespace {
// To use a test fixture, derive a class from testing::Test.
class FilmTest : public testing::Test {
 protected:
  void SetUp() override  {}
  void TearDown() override {}
  public:
  FilmTest(){} 
};
TEST_F(FilmTest, valid_film)
{
    Film film_tx = Film(0x466D,0x28,0x29,false, true,0x3A, 0x61626364);
    EXPECT_EQ(9, film_tx.getPayloadLength());
}
} //namespace