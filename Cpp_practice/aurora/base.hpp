
#include <string>
#include <cstdint> //uint8_t, uint16_t...

#define MAX_BUFF                100
#define MSG_DEFAULT_SIZE        10
#define BASE_HEADER_IN_BYTES    8
#define PAYLOAD_SIZE            0xA
using namespace std;
class Base {
private:
    uint16_t messageId;
    uint8_t senderId;
    uint8_t receiverId;
    uint32_t payloadLength;
    uint8_t *payload;

public:
    Base();
    Base(uint16_t msg, uint8_t sender, uint8_t rcv, uint32_t length, const uint8_t *pData);
    virtual ~Base();

    uint16_t getMessageId();
    uint8_t getSenderId();
    void setSenderId(uint8_t sndId);
    uint8_t getReceiverId();
    void setReceiverId(uint8_t rcvId);
    void setPayloadLength(uint32_t plLength);
    uint32_t getPayloadLength();
    uint8_t *getPayload();
    void setPayload(const uint8_t *pData, uint32_t length);

    virtual string sendText(uint32_t * totalBuffLength);
    virtual void send(char * output);
    virtual void receiveText(string input);
    virtual void receive(char * rx);
    void displayMessage();
};

struct FilmPayload {
    bool lights;
    bool camera;
    uint8_t action;
    uint64_t name;
} __attribute__((packed, aligned(1)));

class Film : public Base {
public:
    Film();
    Film(uint16_t msg, uint8_t sender, uint8_t rcv, FilmPayload fPayload);
};