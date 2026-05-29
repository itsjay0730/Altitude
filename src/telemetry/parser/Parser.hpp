#pragma once
#include <vector>
#include "../models/AircraftState.hpp"

class Parser{
public:
    std::vector<AircraftState> parseOpenSky(const std::string& json);
};

