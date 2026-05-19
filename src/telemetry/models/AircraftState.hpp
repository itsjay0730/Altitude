#pragma once
#include <string>

struct AircraftState{
    std::string icao24;
    std::string callsign;
    std::string originCountry;

    long time;
    long lastContact;

    double longitude;
    double latitude;
    double altitude;

    double velocity;
    double direction;
    double altitudeRate;
    bool inAir;

    std::string squawk;
    bool spi;
    int source;
};