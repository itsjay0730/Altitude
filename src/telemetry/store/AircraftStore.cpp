#include "AircraftStore.hpp"

void AircraftStore::update(const std::vector<AircraftState>& aircrafts) {
    for(const auto& aircraft : aircrafts) {
        map[aircraft.icao24] = aircraft;
    }
};