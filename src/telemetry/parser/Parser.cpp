#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include "Parser.hpp"

bool isCommerical(const std::string& callsign) {
    if(callsign.length() < 4) return false;
    return std::isalpha(callsign[0]) && std::isalpha(callsign[1]) && std::isalpha(callsign[2]);
}

std::string strip(const std::string& callsign) {
    size_t start = callsign.find_first_not_of(" ");
    if(start == std::string::npos) return "";

    size_t end = callsign.find_last_not_of(" ");

    return callsign.substr(start, end - start + 1);
}

std::vector<AircraftState> Parser::parseOpenSky(const std::string& json){
    nlohmann::json data = nlohmann::json::parse(json);
    nlohmann::json states = data["states"];

    std::vector<AircraftState> vec;
    
    for(const auto& state : states) {
        std::string callsign = "";
        if(!state[1].is_null()) callsign = state[1];
        if(isCommerical(strip(callsign))) {
            AircraftState aircraft;
        
            if (!state[0].is_null()) aircraft.icao24 = state[0];
            if (!state[1].is_null()) aircraft.callsign = state[1];
            if (!state[2].is_null()) aircraft.originCountry = state[2];
            if (!state[3].is_null()) aircraft.time = state[3];
            if (!state[4].is_null()) aircraft.lastContact = state[4];
            if (!state[5].is_null()) aircraft.longitude = state[5];
            if (!state[6].is_null()) aircraft.latitude = state[6];
            if (!state[7].is_null()) aircraft.altitude = state[7];
            if (!state[8].is_null()) aircraft.inAir = !state[8];
            if (!state[9].is_null()) aircraft.velocity = state[9];
            if (!state[10].is_null()) aircraft.direction = state[10];
            if (!state[11].is_null()) aircraft.altitudeRate = state[11];
            if (!state[14].is_null()) aircraft.squawk = state[14];
            if (!state[15].is_null()) aircraft.spi = state[15];
            if (!state[16].is_null()) aircraft.source = state[16];

            vec.push_back(aircraft);
        }
    }

    return vec;
}