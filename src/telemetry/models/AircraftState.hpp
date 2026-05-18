#pragma once
#include <string>


struct AircraftState{
    std::string icao24;
    std::string callsign;
    std::string originCountry;

    double longitude;
    double latitude;
    double altitude;

    double velocity;
    double direction;
    double altitudeRate;
};