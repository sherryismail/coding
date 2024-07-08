
#include "base.hpp"
#include <cstring>
#include <iostream> //cout
#include <iomanip> //setfill and setw()
using namespace std;
Film::Film() : Base() {
    lights = false;
    camera = true;
    action = 0x2F;//ASCII print 'o'
    name = 0xdeadbeef;
}
Film::Film(uint16_t msg, uint8_t sender, uint8_t rcv, 
    bool lights, bool camera, uint8_t action, uint64_t name)
    : Base(msg, sender, rcv, 9, nullptr), lights(lights), camera(camera), action(action), name(name)
    {
        //Prepare payload
        uint8_t preamble = lights << 7
        | camera << 6 | action & 0b00111111;

        //64 bits + 8 bit preamble = 9 bytes
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
    uint8_t preamble = lights << 7
        | camera << 6 | action & 0b00111111;

    ostringstream oss;
    oss << hex << setfill('0') << setw(4) <<getMessageId();
    oss << setw(1) << static_cast<int>(getSenderId());
    oss << setw(1) << static_cast<int>(getReceiverId()); //time spent figuring out static_cast
    oss << setfill('0') << setw(8) << getPayloadLength();
    uint8_t filmy[getPayloadLength()];
    uint8_t * src = getPayload();
    memcpy(&filmy[0], src, 9);
    oss << filmy;

    cout << "Tx Info packet: "<< endl;
    for (auto i:oss.str())
        cout << hex <<i<< " ";
    cout << endl;
    return oss.str();
}

void Film::decodeFilmPayload(uint8_t payload)
{
    uint8_t preamble;
    lights = (preamble & 0x8 >> 7);
    camera = (preamble & 0x4 >> 6);
    action = (preamble & 0b00111111 >> 2);
}

void Film::receiveText(string input){
    Base::receiveText(input);

    // uint8_t filmy[9];
    // for (uint32_t i = 0; i < 9; ++i) {
    //     int byte;
    //     iss >> std::hex >> byte;
    //     filmy[i] = static_cast<uint8_t>(byte);
    // }

    // // Update the base class members
    // setPayload(filmy, 9);

    // // Update Film-specific members
    // uint8_t preamble = filmy[0];
    // lights = preamble & 0b10000000;
    // camera = preamble & 0b01000000;
    // action = preamble & 0b00111111;

    // uint64_t beName;
    // memcpy(&beName, filmy + 1, 8);
    // name = be64toh(beName);

    // // Set the message ID, sender ID, and receiver ID
    // setSenderId(sndId);
    // setReceiverId(rcvId);

    // cout << "light"<<lights <<" camera"<< camera << " action"<<action<<endl;
    // cout << "name "<<name;
}

void Film::send(char * output){
    Base::send(output);
}
void Film::receive(char * output){
    Base::receive(output);
}
void Film::displayMessage() {
    Base::displayMessage();
}