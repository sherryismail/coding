#include <iostream>
#include <bitset>
#include <string.h>
#include <sstream> // for std::ostringstream
#include <arpa/inet.h> // for htons, or ntohl Nw to Host
#include <endian.h>    // for htobe64
#include <vector>    
#include <iomanip> //setfill and setw()
using namespace std;
#define MAX_BUFF                100
#define MSG_DEFAULT_SIZE        10
#define BASE_HEADER_IN_BYTES    8
#define PAYLOAD_SIZE            0xA
class Base {

private:
    uint16_t messageId;//no setter/getter if public
    uint8_t senderId;
    uint8_t receiverId;
    uint32_t payloadLength;
    uint8_t * payload;//or char *
public:
    Base(){
        messageId = 0;
        senderId = 0;
        receiverId = 0;
        payloadLength = MSG_DEFAULT_SIZE;
        payload = new uint8_t[MSG_DEFAULT_SIZE];
    }
    Base(uint16_t msg, uint8_t sender, uint8_t rcv, uint32_t length, const uint8_t * pData){
        messageId = msg;
        senderId = sender;
        receiverId = rcv;
        payloadLength = length;
        payload = new uint8_t[length];
        if (pData != nullptr)//TEST if null
            memcpy(payload, pData, length);
    }
    ~Base() {
        delete[] payload;//free the dynamically created memory
    }
    // Getter for messageId
    uint16_t getMessageId(){return messageId;}

    // Getter for senderId
    uint8_t getSenderId() {return senderId; }

    // Setter for senderId
    void setSenderId(uint8_t sndId) {senderId = sndId;}

    // Getter for receiverId
    uint8_t getReceiverId() {return receiverId;}

    // Setter for receiverId
    void setReceiverId(uint8_t rcvId) { receiverId = rcvId;}

    // Getter for payloadLength
    uint32_t getPayloadLength() {return payloadLength;}

    // Setter for payloadLength (mem leak, data corruption, use setPayload instead)
    void setPayloadLength(uint32_t plLength) {payloadLength = plLength;}

    // Getter for payload
    const uint8_t* getPayload() const {return &payload[0];}//?

    // Setter for payload
    void setPayload(const uint8_t* pData, uint32_t length) {
        delete[] payload;//TEST if this called and pData is null
        length = std::min(length, (uint32_t)MAX_BUFF);
        payloadLength = length;
        payload = new uint8_t[payloadLength];
        memcpy(payload, pData, payloadLength);
    }
    //This sends to a File
    virtual string sendText(uint32_t * totalBuffLength){
        std:ostringstream message;
        message << hex << setfill('0') << setw(4) <<messageId << senderId //set 4 characters
                << receiverId << setfill('0') << setw(8) << payloadLength
                << std::string(reinterpret_cast<char *>(payload), payloadLength); 

        *totalBuffLength = message.str().length();
        // cout << "Tx Info packet: "<< endl;
        // for (auto i:message.str())
        //     cout << hex <<i<< " ";
        return message.str();
    }

    //This sends only the bytes to the driver
    virtual void send(char * output){
        char * pOutput = output;
        *(uint16_t *)pOutput = messageId;
        pOutput += 2;
        *pOutput = senderId;
        pOutput++;
        *pOutput = receiverId;
        pOutput++;
        //TEST VALUE payloadLength = (32 << 8)|33;
        *(uint32_t *)pOutput = payloadLength;
        pOutput += 4;
        memcpy(pOutput, payload, payloadLength);
        // cout << "In bytes:";
        // for (int i=0; i < payloadLength+BASE_HEADER_IN_BYTES; i++)
        //     cout << "["<< i <<"]="<<output[i]<<",";
    }
    virtual void receive(char * rx){
        char * pRx = rx;
        messageId = *(uint16_t *)pRx;
        pRx += 2;
        senderId = *pRx;
        pRx++;
        receiverId = *pRx;
        pRx++;
        //TEST VALUE payloadLength = (32 << 8)|33;
        payloadLength = *(uint32_t *)pRx;
        pRx += 4;
        char * temp = (char *)malloc(payloadLength);
        memcpy(temp, pRx, payloadLength);
        cout << endl << "resize...... "<< endl;
        setPayload((const uint8_t *) temp,payloadLength);
        free(temp);
        // cout << "In bytes:";
        // for (int i=0; i < payloadLength+BASE_HEADER_IN_BYTES; i++)
        //     cout << "["<< i <<"]="<<output[i]<<",";
    }
    virtual void receiveText(string input){
        std::istringstream iss(input);// stoi(input)
        // std::vector<uint8_t> bytes(input.begin(), input.end());//or memcpy(char, str,length)
        // cout << endl<< "Rx Info packet: "<< endl;
        // for (auto i:input)
        //     cout << hex << i;
        // cout << endl;
        iss >> setw(4) >> hex >>messageId >> senderId >> receiverId;
        uint32_t n = 0x20, i=0; //'0' follow
        while (n== 0x20)
        {
            iss >> n; i++;
        }  
        iss >>setw(8) >>payloadLength;
        iss.read(reinterpret_cast<char*>(payload), payloadLength);//setPayload();
    }
    // Method to display message details
    void displayMessage() {
         std:ostringstream message;
         message << "Message ID: "<< std::to_string(messageId) + "\n"
                << "Sender ID: " + std::to_string(senderId) + "\n"
                << "Receiver ID: " + std::to_string(receiverId) + "\n"
                << "Payload Length: " + std::to_string(payloadLength) + "\n"
                << "Payload: " + std::string(payload, payload + payloadLength)+ "\n";//payload was char array
                // std::string(reinterpret_cast<char *>(payload), payloadLength) + "\n"; // payload was char array
        std::cout << message.str();
    }
};
// Define the FilmPayload struct
struct FilmPayload {
    bool lights;// 1 byte
    bool camera; // 1 byte
    uint8_t action;
    uint64_t name;
}__attribute__((packed,aligned(1)));
class Film: public Base {
public:
    bitset<8> record;
    Film():Base(){}
    Film(uint8_t msg, uint8_t sender, uint8_t rcv, FilmPayload fPayload)
        : Base(msg, sender, rcv, 9, nullptr)
        {
            //Prepare payload
            uint8_t preamble = fPayload.lights << 7
            | fPayload.camera << 6 | fPayload.action & 0b00111111;

            //64 bits + 8 bit preamble = 9 bytes
            uint8_t filmy[9];
            //preamble= htons(preamble);
            //fPayload.name = htobe64(fPayload.name);
            filmy[0] = preamble;
            memcpy(filmy+1, &fPayload.name, 8);
            setPayload(filmy, 9);
        }
   ~Film() { }
};

int main(){
    Base * base = new Base;//TEST the returns are 0
    // flush:cout << "Empty class: senderID "<<(int)base->getSenderId() << ", length "<< base->getPayloadLength()<<endl;
    base->displayMessage();
    // delete base;
    uint8_t cc[MSG_DEFAULT_SIZE] = {'5','6','7','8','9','a','b','c','d','e'};
    Base * base1 = new Base(0x7878,0x55,0x56,PAYLOAD_SIZE, cc);//test if messageId is 65530 or 1
    base1->displayMessage();
    uint32_t bufferlength = base1->getPayloadLength() + BASE_HEADER_IN_BYTES;
    char output[bufferlength];
    base1->send(&output[0]);
    base->receive(&output[0]);
    // string buffer = base1->sendText(&bufferlength);
    // base1->receiveText(buffer);
    base->displayMessage();
    delete base1;

    // FilmPayload f = {true, true, 5, 0x1234};
    // cout << "struct: "<<sizeof(FilmPayload)<< endl;
    // Film film = Film(10,20,30,f);
    return 0;
}


/* strings = string((char *) &buffer);
 uint32_t x = 0x1234;
    cout << hex<< x << ", " << htons(x) << dec<< endl;
  // Copy constructor
    Message(const Message& other) 
        : messageId(other.messageId), senderId(other.senderId), receiverId(other.receiverId), payloadLength(other.payloadLength) {
        payload = new char[payloadLength];
        std::memcpy(payload, other.payload, payloadLength);
    }

    // Assignment operator
    Message& operator=(const Message& other) {
        if (this == &other) {
            return *this;
        }

        messageId = other.messageId;
        senderId = other.senderId;
        receiverId = other.receiverId;
        payloadLength = other.payloadLength;

        delete[] payload;
        payload = new char[payloadLength];
        std::memcpy(payload, other.payload, payloadLength);

        return *this;
        strcpy(char_array, s.c_str()); // copying the contents of the string to char array 
    }*/