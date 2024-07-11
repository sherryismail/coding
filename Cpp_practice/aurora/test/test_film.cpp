#include <base.hpp>
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
TEST_F(FilmTest, empty_film)
{
    Film film_tx = Film();
    EXPECT_EQ(9, film_tx.getPayloadLength());
    //stack smashing detected, so assigne a size
}
TEST_F(FilmTest, receive_and_send_correct_film)
{
  Film film_tx = Film(0x466D,0x28,0x29,false, true,0x3A, 0x61626364DEADBEEF);
  // // 0x46=m 0x6D=F 0x28=( 0x29=) preamble combines to 'z'
  string str = film_tx.sendText();

  Film film_rx = Film();
  film_rx.receiveText(str);

  EXPECT_EQ(film_tx.getMessageId(),film_rx.getMessageId());
  EXPECT_EQ(film_tx.getSenderId(),film_rx.getSenderId());
  EXPECT_EQ(film_tx.getReceiverId(),film_rx.getReceiverId());
  EXPECT_EQ(film_tx.getPayloadLength(),film_rx.getPayloadLength());
  EXPECT_EQ(film_tx.getLights(),film_rx.getLights());
  EXPECT_EQ(film_tx.getCamera(),film_rx.getCamera());
  EXPECT_EQ(film_tx.getAction(),film_rx.getAction());
  EXPECT_EQ(film_tx.getName(),film_rx.getName());
}
TEST_F(FilmTest, receive_and_send_empty_film)
{
  // Assume: When an empty Film object is initialised, a buffer
  // of FILM_PAYLOAD_LEN will still be created
  Film film_tx, film_rx = Film();
  string str = film_tx.sendText();
  film_rx.receiveText(str);

  EXPECT_EQ(film_tx.getMessageId(),film_rx.getMessageId());
  EXPECT_EQ(film_tx.getSenderId(),film_rx.getSenderId());
  EXPECT_EQ(film_tx.getReceiverId(),film_rx.getReceiverId());
  EXPECT_EQ(film_tx.getPayloadLength(),film_rx.getPayloadLength());
  EXPECT_EQ(film_tx.getLights(),film_rx.getLights());
  EXPECT_EQ(film_tx.getCamera(),film_rx.getCamera());
  EXPECT_EQ(film_tx.getAction(),film_rx.getAction());
  //endian-ness preserved after receiving
  EXPECT_EQ(film_tx.getName(),film_rx.getName());

}
} //namespace