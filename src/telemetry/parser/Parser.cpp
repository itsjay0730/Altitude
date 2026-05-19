#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include "Parser.hpp"

std::vector<AircraftState> Parser::parseOpenSky(const std::string& json){
    nlohmann::json data = nlohmann::json::parse(json);
    nlohmann::json states = data["states"];

    std::vector<AircraftState> vec;
    
    for(const auto& state : states) {
        AircraftState aircraft;
        
        aircraft.icao24 = state[0];
        aircraft.callsign = state[1];
        aircraft.originCountry = state[2];
        aircraft.longitude = state[5];
        aircraft.latitude = state[6];
        aircraft.altitude = state[7];
        aircraft.velocity = state[9];
        aircraft.direction = state[10];
        aircraft.altitudeRate = state[11];

        vec.push_back(aircraft);
    }

}