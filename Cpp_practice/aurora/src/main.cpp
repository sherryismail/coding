#include "base.hpp"
#include <iostream>

//g++ -o program main.cpp base.cpp film.cpp
int main(){
    uint8_t cc[MSG_DEFAULT_SIZE] = {'5','6','7','8','9','a','b','c','d','e'};
    // 0x78 x, 0x55 U, 0x56 V, ...
    Base * base1 = new Base(0x7878,0x55,0x4A,PAYLOAD_SIZE, cc);//test if messageId is 65530 or 1
    Base * base2 = new Base;//TEST the returns are 0
    base2->displayMessage();    
    
    // uint32_t bufferlength;
    // bufferlength = base1->getPayloadLength() + BASE_HEADER_IN_BYTES;
    // char buffer[bufferlength];
    // base1->send(&buffer[0]);
    // base2->receive(&buffer[0]);
    
    string text = base1->sendText();
    base2->receiveText(text);
    base2->displayMessage();
    delete base1;
    delete base2;

    // Film film_tx = Film(0x466D,0x28,0x29,false, true,0x3A, 0x61626364);
    // // 0x46=m 0x6D=F 0x28=( 0x29=) preamble combines to 'z'
    // Film film_rx = Film();
    // film_tx.displayMessage();

    // text = film_tx.sendText();
    // film_rx.receiveText(text);

    // bufferlength = film_tx.getPayloadLength() + BASE_HEADER_IN_BYTES;
    // char buffer[bufferlength];   
    // film_tx.send(buffer);
    // film_rx.receive(buffer); 
    
    // film_rx.displayMessage();
    return 0;
}