#pragma once
#include <unordered_map>
#include <vector>
#include "../models/AircraftState.hpp"

class AircraftStore {
private:
    std::unordered_map<std::string, AircraftState> map;

public:

    void update(const std::vector<AircraftState>& aircrafts);
    void removeStale();
    std::vector<AircraftState> getAll();
};