#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include "Parser.hpp"

std::vector<AircraftState> Parser::parseOpenSky(const std::string& json){
    nlohmann::json data = nlohmann::json::parse(json);
    nlohmann::json states = data["states"];

    std::vector<AircraftState> vec;
    

}