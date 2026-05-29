#include <ctime>
#include "AircraftStore.hpp"

void AircraftStore::update(const std::vector<AircraftState>& aircrafts) {
    for(const auto& aircraft : aircrafts) {
        map[aircraft.icao24] = aircraft;
    }
};

void AircraftStore::removeStale() {
    long currTime = std::time(nullptr);

    for(auto it = map.begin(); it != map.end();) {
        long age = currTime - it->second.lastContact;

        if(age > 300) {
            it = map.erase(it);
        }else {
            ++it;
        }
    }
};

std::vector<AircraftState> AircraftStore::getAll() {
    std::vector<AircraftState> vec;

    for(const auto& pair : map) {
        vec.push_back(pair.second);
    }

    return vec;
};