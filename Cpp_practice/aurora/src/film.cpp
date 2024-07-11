
#include "base.hpp"
#include <cstring>
#include <iostream> //cout
#include <iomanip> //setfill and setw()
using namespace std;
#define FILM_PAYLOAD_LEN    9 //64 bits + 8 bit preamble = 9 bytes can it be __packed___?
Film::Film() : Base(), lights(false), camera(true), action(0), name(0) {
    //if name != 0 GTEST: stack smashing detected. So force a length
    Base::setPayloadLength(FILM_PAYLOAD_LEN);
    initialisePreamble();
}
Film::Film(uint16_t msg, uint8_t sender, uint8_t rcv, 
    bool lights, bool camera, uint8_t action, uint64_t name)
    : Base(msg, sender, rcv, FILM_PAYLOAD_LEN, nullptr), lights(lights), camera(camera), action(action), name(name)
    {
        initialisePreamble();
    }

int8_t Film::initialisePreamble(){
    //Prepare payload
    return PreparePayload();       
}

int8_t Film::PreparePayload(){
    uint8_t preamble = (lights << 7)
    | (camera << 6) | (action & 0b00111111);

    uint8_t filmy[getPayloadLength()];
    //preamble= htons(preamble); //Network order does not affect 8-bit words
    filmy[0] = preamble;
    name = htobe64(name); //Network byte order (Big endian) applied
    memcpy(filmy+1, &name, FILM_PAYLOAD_LEN-1);
    return setPayload(filmy, FILM_PAYLOAD_LEN);
}
bool Film::getLights() {return lights; }
void Film::setLights(bool l) {lights = l;}
bool Film::getCamera() {return camera; }
void Film::setCamera(bool c) {camera = c;}
uint8_t Film::getAction() {return action; }
void Film::setAction(uint8_t a) {action = a & 0b00111111;}
uint64_t Film::getName() {return name; }
void Film::setName(uint64_t n) {name = n;}

string Film::sendText()
{
    //prepare the payload
    int8_t retVal = PreparePayload();
    if (retVal != 0)
        return NULL;
    return Base::sendText();
}

void Film::decodePreamble(uint8_t preamble)
{
    lights = (preamble >> 7);
    camera = (preamble >> 6);
    action = (preamble & 0b00111111);
}
void Film::decodePayload(uint8_t * rx)
{
    decodePreamble(rx[0]);
    if (getPayloadLength() == FILM_PAYLOAD_LEN){
        name = *(uint64_t *)&rx[1]; //very C like
        name = htole64(name); //Convert to Host byte order from network byte (little endian)
    }
    //else name is not overwritten
}

void Film::receiveText(string input){
    Base::receiveText(input);
    //decode the payload
    uint8_t * rx = getPayload();
    decodePayload(rx);
}

void Film::send(char * output){
    Base::send(output);
}
int8_t Film::receive(char * output){
    Base::receive(output);
    //decode the payload
    uint8_t * rx = getPayload();
    decodePreamble(rx[0]);
    decodePayload(rx);
    return 0;
}
void Film::displayMessage() {
    cout << "Lights:" + std::to_string(lights) + ", "
        << "Camera: " + std::to_string(camera) + ", " //seg fault because + not <<
        << "Action: " << hex << setw(2) << setfill('0') << static_cast<int>(action) << ", "
        << "Name: "  << hex << setw(2) << setfill('0') << name <<"\n";
    Base::displayMessage();

}