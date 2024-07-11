#include <base.hpp>
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
TEST_F(BaseTest, payload_length_too_long_add_junk_data)
{
    uint8_t cc[MSG_DEFAULT_SIZE] = {'5','6','7','8','9','a','b','c','d','e'};
    Base * base = new Base(0x7878,0x55,0x4A,PAYLOAD_SIZE, cc);
    int x = base->getPayloadLength();
    base->displayMessage();
    EXPECT_EQ(PAYLOAD_SIZE, x);

    // Other than the extra junk, first part of payload is the same as initialised
    uint8_t* pl = base->getPayload();
    EXPECT_EQ(0,memcmp(cc, pl, MSG_DEFAULT_SIZE));
}
TEST_F(BaseTest, null_pkt){
  Base base = Base();
    ASSERT_TRUE(0 == base.getPayloadLength());
    EXPECT_EQ(nullptr, base.getPayload());
    EXPECT_EQ(-2, base.setPayload(nullptr, PAYLOAD_SIZE));
}
}
//if length is zero
TEST_F(BaseTest, handle_payload_length_is_zero)
{
  uint8_t cc[MSG_DEFAULT_SIZE] = {'5','6','7','8','9','a','b','c','d','e'};
  Base * base = new Base(0x7878,0x55,0x4A, 0, cc);
  uint32_t x = base->getPayloadLength();
  EXPECT_EQ(0, x);
  EXPECT_EQ(-1, base->setPayload(cc,x));
}
// if payload is a string
TEST_F(BaseTest, payload_is_not_char_but_string){
  string str = "Hello world";
  Base * base = new Base(1,2,3, str.length(), (uint8_t *)str.c_str());
  uint32_t x = base->getPayloadLength();
  EXPECT_EQ(str.length(), x);
}
//if length is larger than MAX size
TEST_F(BaseTest, too_big_payload_then_set_upper_limit){
  string str = "Hello world";
  Base base = Base(0,0,0, 2000, (uint8_t *)str.c_str());
  EXPECT_EQ(MAX_BUFF, base.getPayloadLength());
}
// if pData is null but rest of the packet is correct
TEST_F(BaseTest, valid_pkt_but_null_payload){
  Base base = Base(0x7878,0x55,0x4A,PAYLOAD_SIZE, nullptr);
  EXPECT_EQ(-2, base.setPayload(nullptr, PAYLOAD_SIZE));
}

TEST_F(BaseTest,receive_and_send_correct_char){
  uint8_t cc[MSG_DEFAULT_SIZE] = {'5','6','7','8','9','a','b','c','d','e'};
  Base base = Base(0x7878,0x55,0x4A, MSG_DEFAULT_SIZE, cc);
  uint32_t bufferlength;
  bufferlength = base.getPayloadLength() + BASE_HEADER_IN_BYTES;
  char buffer[bufferlength];
  base.send(buffer);

  Base base_rx = Base();
  EXPECT_EQ(0, base_rx.receive(buffer)); 
  EXPECT_EQ(base.getMessageId(),base_rx.getMessageId());
  EXPECT_EQ(base.getSenderId(),base_rx.getSenderId());
  EXPECT_EQ(base.getReceiverId(),base_rx.getReceiverId());
  EXPECT_EQ(base.getPayloadLength(),base_rx.getPayloadLength());
  EXPECT_TRUE(MSG_DEFAULT_SIZE == base_rx.getPayloadLength());

  const char * x = (char *)base.getPayload();
  const char * y = (char *)base_rx.getPayload();
  for (int i = 0; i < MSG_DEFAULT_SIZE; ++i) {
    EXPECT_EQ(x[i], y[i]) << "Payloads differ at index " << i;
  }
}
TEST_F(BaseTest, send_and_receive_empty_char)
{
  Base base = Base();
  //This should return zero
  uint32_t bufferlength = base.getPayloadLength() + BASE_HEADER_IN_BYTES;
  EXPECT_EQ(bufferlength,BASE_HEADER_IN_BYTES);
  //Assumed behavior that we want to create a packet anyway
  char buffer[bufferlength];
  base.send(buffer);
  
  //start with non-empty receiver object and check if it should become empty
  string str = "Hello world";
  Base base_rx = Base(1,2,3, str.length(), (uint8_t *)str.c_str());
  //payload length is zero
  EXPECT_EQ(-2, base_rx.receive(buffer));
  EXPECT_EQ(base.getMessageId(),base_rx.getMessageId());
  EXPECT_EQ(base.getSenderId(),base_rx.getSenderId());
  EXPECT_EQ(base.getReceiverId(),base_rx.getReceiverId());
  EXPECT_EQ(base.getPayloadLength(),base_rx.getPayloadLength());
}

TEST_F(BaseTest, receive_and_send_correct_string)
{
  string str = "Hello world";
  Base base = Base(1,2,3, str.length(), (uint8_t *)str.c_str());
  string buffer = base.sendText();
  
  Base base_rx = Base();
  base_rx.receiveText(buffer); 
  EXPECT_EQ(base.getMessageId(),base_rx.getMessageId());
  EXPECT_EQ(base.getSenderId(),base_rx.getSenderId());
  EXPECT_EQ(base.getReceiverId(),base_rx.getReceiverId());
  EXPECT_EQ(base.getPayloadLength(),base_rx.getPayloadLength());
  EXPECT_EQ(0,memcmp(base.getPayload(), base_rx.getPayload(), str.length()));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//Consider gcovr