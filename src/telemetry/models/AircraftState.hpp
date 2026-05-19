#pragma once
#include <string>


struct AircraftState{
    std::string icao24;
    std::string callsign;
    std::string originCountry;

    std::string time;
    std::string lastContact;

    double longitude;
    double latitude;
    double altitude;

    double velocity;
    double direction;
    double altitudeRate;
    bool inAir;

    double squawk;
    double spi;
    std::string source;
};