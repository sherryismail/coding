
#include <string>
#include <cstdint> //uint8_t, uint16_t...

#define MAX_BUFF                100
#define MSG_DEFAULT_SIZE        0xA
#define BASE_HEADER_IN_BYTES    0x8
#define PAYLOAD_SIZE            0xC
using namespace std;
class Base {
protected:
    uint16_t messageId;
private:
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
    int8_t setPayloadLength(uint32_t plLength);
    uint32_t getPayloadLength();
    uint8_t *getPayload();
    int8_t setPayload(const uint8_t *pData, uint32_t length);

    virtual string sendText();
    virtual void send(char * output);
    virtual void receiveText(string input);
    virtual int8_t receive(char * rx);
    void displayMessage();
};

// struct FilmPayload {
// } __attribute__((packed, aligned(1)));

class Film : public Base {
private:
    bool lights;
    bool camera;
    uint8_t action;
    uint64_t name;

public:
    Film();
    Film(uint16_t msg, uint8_t sender, uint8_t rcv,
    bool lights, bool camera, uint8_t action, uint64_t name);
    void initialisePreamble();
    bool getLights();
    void setLights(bool l);
    bool getCamera();
    void setCamera(bool c);
    uint8_t getAction();
    void setAction(uint8_t n);
    uint64_t getName();
    void setName(uint64_t n);
    virtual string sendText();
    virtual void receiveText(string input);
    virtual void send(char * output);
    virtual int8_t receive(char * rx);
    void displayMessage();
    void decodeFilmPayload(uint8_t p);
};
//could make payload length const?