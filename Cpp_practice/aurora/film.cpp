
#include "base.hpp"
#include <cstring>
Film::Film() : Base() {}
Film::Film(uint16_t msg, uint8_t sender, uint8_t rcv, FilmPayload fPayload)
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