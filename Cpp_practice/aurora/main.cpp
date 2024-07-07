#include "base.hpp"
#include <iostream>

//g++ -o program main.cpp base.cpp film.cpp
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