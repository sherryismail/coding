#include "base.hpp"
#include <iostream>
#include <sstream> // for std::ostringstream
#include <arpa/inet.h> // for htons, or ntohl Nw to Host
#include <endian.h>    // for htobe64 
#include <iomanip> //setfill and setw()
#include <cstring> //memcpy

using namespace std;
Base::Base() {
        messageId = 0;
        senderId = 0;
        receiverId = 0;
        payloadLength = MSG_DEFAULT_SIZE;
        payload = new uint8_t[MSG_DEFAULT_SIZE];
    }

Base::Base(uint16_t msg, uint8_t sender, uint8_t rcv, uint32_t length, const uint8_t * pData){
    messageId = msg;
    senderId = sender;
    receiverId = rcv;
    payloadLength = length;
    payload = new uint8_t[length];
    if (pData != nullptr)//TEST if null
        memcpy(payload, pData, length);
}
Base::~Base() {
    delete[] payload;//free the dynamically created memory
}
// Getter for messageId
uint16_t Base::getMessageId(){return messageId;}

// Getter for senderId
uint8_t Base::getSenderId() {return senderId; }

// Setter for senderId
void Base::setSenderId(uint8_t sndId) {senderId = sndId;}

// Getter for receiverId
uint8_t Base::getReceiverId() {return receiverId;}

// Setter for receiverId
void Base::setReceiverId(uint8_t rcvId) { receiverId = rcvId;}

// Getter for payloadLength
uint32_t Base::getPayloadLength() {return payloadLength;}

// Setter for payloadLength (mem leak, data corruption, use setPayload instead)
void Base::setPayloadLength(uint32_t plLength) {payloadLength = plLength;}

// Getter for payload
uint8_t* Base::getPayload() {return payload;}

// Setter for payload
void Base::setPayload(const uint8_t* pData, uint32_t length) {
    delete[] payload;//TEST if this called and pData is null
    length = std::min(length, (uint32_t)MAX_BUFF);
    payloadLength = length;
    payload = new uint8_t[payloadLength];
    if (pData != nullptr)
        memcpy(payload, pData, payloadLength);
}
//This sends to a File
string Base::sendText(uint32_t * totalBuffLength){
    std:ostringstream message;
    message << hex << setfill('0') << setw(4) <<messageId //set 4 characters
            << setfill('0') << setw(1) << senderId 
            << setfill('0') << setw(1) << receiverId
            << setfill('0') << setw(8) << payloadLength
            << std::string(reinterpret_cast<char *>(payload), payloadLength); 

    *totalBuffLength = message.str().length();
    // cout << "Tx Info packet: "<< endl;
    // for (auto i:message.str())
    //     cout << hex <<i<< " ";
    return message.str();
}

//This sends only the bytes to the driver
void Base::send(char * output){
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
    // cout << "send() full frame:";
    // for (int i=0; i < payloadLength+BASE_HEADER_IN_BYTES; i++)
    //     cout << "["<< i <<"]="<<output[i]<<",";
    // cout <<endl;
}
void Base::receive(char * rx){
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
    setPayload((const uint8_t *) temp,payloadLength);
    free(temp);
    // cout << endl<<"receive() only payload:";
    // for (int i=0; i < payloadLength; i++)
    //     cout << "["<< i <<"]="<<pRx[i]<<",";
    // cout <<endl;
}
void Base::receiveText(string input){
    std::istringstream iss(input);// stoi(input)
    // std::vector<uint8_t> bytes(input.begin(), input.end());//or memcpy(char, str,length)
    cout << endl<< "Rx Info packet: "<< endl;
    for (auto i:input)
        cout << hex << i;
    cout << endl;
    iss >> setw(4) >> hex >>messageId >> senderId >> receiverId;
    uint32_t n = 0x30, i=0; //'0' follow
    while (n== 0x30)
    {
        iss >> hex>>n; i++;
    }  
    iss.ignore('0');//does not work
    iss >>setw(8) >> setfill('0')>> hex >>payloadLength;//does not change
    cout << "MsgId="<<hex << messageId<< " SndId="<< hex<< (int)senderId << " rcvId="<< (int)receiverId <<endl;
    cout << "extra 0s = " << i <<", payloadLength= " << payloadLength<<endl;
    
    string temp(payloadLength, '0');
    setPayload((uint8_t *)&temp, payloadLength);
    iss.read(reinterpret_cast<char*>(payload), payloadLength);//could use setPayload();?
    cout <<"RxText payload: "<< endl;
    for (int i = 0; i < payloadLength; i++)
        cout << "["<< i <<"]="<<hex<<payload[i]<<",";
}
// Method to display message details
//what doe s aconst do?
void Base::displayMessage() {
        std:ostringstream message;
        message << "Message ID: "<< std::to_string(messageId) + "\n"
            << "Sender ID: " + std::to_string(senderId) + "\n"
            << "Receiver ID: " + std::to_string(receiverId) + "\n"
            << "Payload Length: " + std::to_string(payloadLength) + "\n"
            << "Payload: " + std::string(payload, payload + payloadLength)+ "\n";//payload was char array
            // std::string(reinterpret_cast<char *>(payload), payloadLength) + "\n"; // payload was char array
    std::cout << message.str();
}
// error: ‘virtual’ outside class declaration only in declaration
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