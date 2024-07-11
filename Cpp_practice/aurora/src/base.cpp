#include "base.hpp"
#include <iostream>
#include <sstream> // for std::ostringstream
#include <arpa/inet.h> // for htons, or ntohl Nw to Host
#include <endian.h>    // for htobe64 
#include <iomanip> //setfill and setw()
#include <cstring> //memcpy

using namespace std;
Base::Base():
messageId(0), senderId(0), receiverId(0), payloadLength(0), payload(nullptr) {}

Base::Base(uint16_t msg, uint8_t sender, uint8_t rcv, uint32_t length, const uint8_t * pData)
: messageId(msg), senderId(sender), receiverId(rcv), payloadLength(length), payload(nullptr) 
{
    if (pData == nullptr) //GTEST: Add a printf although this is checked later
        cout << "Payload is nullptr";
    setPayload(pData, length);
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
// terminate called after throwing an instance of 'std::logic_error'
//  what():  basic_string::_M_construct null not valid
int8_t Base::setPayloadLength(uint32_t plLength) {
    if (plLength > MAX_BUFF)//Changing from void to error code return during GTEST
        return -1;
    else{
        payloadLength = plLength;
        return 0;
    }
    }

// Getter for payload
uint8_t* Base::getPayload() {return payload;}

// Setter for payload
int8_t Base::setPayload(const uint8_t* pData, uint32_t length) {
    delete[] payload; //GTEST: free(): double free detected in tcache 2 if called with receive()->malloc
    length = std::min(length, (uint32_t)MAX_BUFF); //GTEST that length is not too high
    if (length == 0)//GTEST: pData is valid but length=0
        return -1;
    payloadLength = length;
    payload = new uint8_t[payloadLength];  
    if (pData != nullptr) //GTEST : Seg fault if pData = null
    {
        memcpy(payload, pData, payloadLength);
        return 0;
    }
    else
        return -2;
}

//This sends only the bytes to the driver. ALERT: The size should be preallocated
void Base::send(char * output){
    if (output == nullptr)
        return;
    char * pOutput = output;
    *(uint16_t *)pOutput = messageId;
    pOutput += 2;
    *pOutput = senderId;
    pOutput++;
    *pOutput = receiverId;
    pOutput++;
    *(uint32_t *)pOutput = payloadLength;
    pOutput += 4;
    memcpy(pOutput, payload, payloadLength);
    // cout << "send() full frame:";
    // for (int i=0; i < payloadLength+BASE_HEADER_IN_BYTES; i++)
    //     cout << "["<< i <<"]="<<output[i]<<",";
    // cout <<endl;
}
int8_t Base::receive(char * rx){// GTEST: should have return codes
    if (rx == nullptr)
        return -3;
    char * pRx = rx;
    messageId = *(uint16_t *)pRx;
    pRx += 2;
    senderId = *pRx;
    pRx++;
    receiverId = *pRx;
    pRx++;
    payloadLength = *(uint32_t *)pRx;
    if (payloadLength > MAX_BUFF){ //GTEST: if corrupt pkt
        cout << "Rx payload length is too high"<<endl;
        return -1;
    }
    if (payloadLength == 0)//GTEST
    {
        cout << "Rx payload length is zero"<<endl;
        return -2;
        /*We could clear out the payload buffer here so the user does not 
        accidentally mistake the stale data as a a valid one. Or the caller
        can handle the return code to not read *rx
        */
    }
    pRx += 4;
    return setPayload((const uint8_t *) pRx,payloadLength);
    // cout << endl<<"receive() only payload:";
    // for (int i=0; i < payloadLength; i++)
    //     cout << "["<< i <<"]="<<pRx[i]<<",";
    // cout <<endl;
}

//This sends to a File
string Base::sendText(){
    //time spent on not using a separator and fixed bytes->string
    ostringstream oss;
    oss<< hex << setw(4) << messageId << "|"
    << setw(2) <<static_cast<int>(senderId) << "|"
    << setw(2) <<static_cast<int>(receiverId) << "|"
    << setw(8) <<payloadLength << "|";
    for (uint32_t i = 0; i < payloadLength; ++i) {
            oss << setw(2) << setfill('0') << hex << static_cast<int>(payload[i]);
        }
    return oss.str();
}
void Base::receiveText(string input){
    std::istringstream ss(input);
    // cout << endl<< "Rx Info packet: "<< endl;
    // for (auto i:input)
    //     cout << hex << i;
    // cout << endl;
    string segment;
    getline(ss, segment, '|');
    messageId = (uint16_t)(stoi(segment, nullptr, 16));

    getline(ss, segment, '|');
    senderId = static_cast<uint8_t>(stoi(segment, nullptr, 16));//TEST if hex works

    getline(ss, segment, '|');
    receiverId = static_cast<uint8_t>(stoi(segment, nullptr, 16));

    getline(ss, segment, '|');
    uint32_t plLength = static_cast<uint32_t>(stoul(segment, nullptr, 16));
    //TEST plLength = 0
    uint8_t temp[plLength];//no new heap
    setPayload(temp,plLength);

    string payloadStr;
    getline(ss, payloadStr, '|');
    //every byte is 2 HEX characters
    for (uint32_t i = 0; i < payloadLength; ++i) {
        payload[i] = static_cast<uint8_t>(stoi(payloadStr.substr(i * 2, 2), nullptr, 16));
    }
}
// Method to display message details
//what does a const do?
void Base::displayMessage() {
        ostringstream message;
        message << "Message ID: "<< std::to_string(messageId) + "\n"
            << "Sender ID: " + std::to_string(senderId) + "\n"
            << "Receiver ID: " + std::to_string(receiverId) + "\n"
            << "Payload Length: " + std::to_string(payloadLength) + "\n"
            << "Payload: " + std::string(payload, payload + payloadLength)+ "\n";//payload was char array
    std::cout << message.str();
}