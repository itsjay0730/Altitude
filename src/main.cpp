#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "telemetry/fetcher/Fetcher.hpp"
#include "telemetry/parser/Parser.hpp"
#include "telemetry/store/AircraftStore.hpp"

int main() {
    Fetcher fetcher;
    Parser parser;
    AircraftStore store;

    while(true) {
        try {
            std::string jsonResp = fetcher.fetchOpenSky();
            std::vector<AircraftState> aircrafts = parser.parseOpenSky(jsonResp);

            store.update(aircrafts);
            store.removeStale();

            std::vector<AircraftState> allAircrafts = store.getAll();

            //Just a test
            std::cout << "Live Aircrafts: " << allAircrafts.size() << std::endl;

        }catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }


        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}

