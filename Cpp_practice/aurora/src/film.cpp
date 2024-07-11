
#include "base.hpp"
#include <cstring>
#include <iostream> //cout
#include <iomanip> //setfill and setw()
using namespace std;
Film::Film() : Base(), lights(false), camera(true), action(0x2F), name(0xdeadbeef) {
    initialisePreamble();
}
Film::Film(uint16_t msg, uint8_t sender, uint8_t rcv, 
    bool lights, bool camera, uint8_t action, uint64_t name)
    : Base(msg, sender, rcv, 9, nullptr), lights(lights), camera(camera), action(action), name(name)
    {
        initialisePreamble();
    }

void Film::initialisePreamble(){
//Prepare payload
        uint8_t preamble = (lights << 7)
        | (camera << 6) | (action & 0b00111111);

        //64 bits + 8 bit preamble = 9 bytes can it be __packed___?
        uint8_t filmy[9];
        //preamble= htons(preamble);
        //fPayload.name = htobe64(fPayload.name);
        filmy[0] = preamble;
        memcpy(filmy+1, &name, 8);
        setPayload(filmy, 9);
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
    uint8_t preamble = (lights << 7)
        | (camera << 6) | (action & 0b00111111);

    uint8_t filmy[getPayloadLength()];
    filmy[0] = preamble;
    memcpy(filmy+1, &name, 8);
    setPayload(filmy, 9);
    return Base::sendText();
}

void Film::decodeFilmPayload(uint8_t preamble)
{
    lights = (preamble >> 7);
    camera = (preamble >> 6);
    action = (preamble & 0b00111111);
}

void Film::receiveText(string input){
    Base::receiveText(input);
    //decode the payload
    uint8_t * rx = getPayload();
    decodeFilmPayload(rx[0]);
    if (getPayloadLength() == 9)
        name = *(uint64_t *)&rx[1]; //very C like
}

void Film::send(char * output){
    Base::send(output);
}
int8_t Film::receive(char * output){
    Base::receive(output);
    //decode the payload
    uint8_t * rx = getPayload();
    decodeFilmPayload(rx[0]);
    if (getPayloadLength() == 9)
        name = *(uint64_t *)&rx[1]; //very C like
    return 0;
}
void Film::displayMessage() {
    cout << "Lights:" + std::to_string(lights) + ", "
        << "Camera: " + std::to_string(camera) + ", " //seg fault because + not <<
        << "Action: " << hex << setw(2) << setfill('0') << static_cast<int>(action) << ", "
        << "Name: "  << hex << setw(2) << setfill('0') << name <<"\n";
    Base::displayMessage();

}