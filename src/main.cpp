#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "telemetry/fetcher/Fetcher.hpp"
#include "telemetry/parser/Parser.hpp"
#include "telemetry/store/AircraftStore.hpp"

void printPlane(AircraftState plane) {
    std::cout << "----------------------------------" << std::endl;

    std::cout << "ICAO24: " << plane.icao24 << std::endl;
    std::cout << "Callsign: " << plane.callsign << std::endl;
    std::cout << "Country: " << plane.originCountry << std::endl;
    std::cout << "Time: " << plane.time << std::endl;
    std::cout << "Last Contact: " << plane.lastContact << std::endl;
    std::cout << "Longitude: " << plane.longitude << std::endl;
    std::cout << "Latitude: " << plane.latitude << std::endl;
    std::cout << "Altitude: " << plane.altitude << std::endl;
    std::cout << "Velocity: " << plane.velocity << std::endl;
    std::cout << "Heading: " << plane.direction << std::endl;
    std::cout << "Vertical Rate: " << plane.altitudeRate << std::endl;
    std::cout << "In Air: " << plane.inAir << std::endl;
    std::cout << "Squawk: " << plane.squawk << std::endl;
    std::cout << "SPI: " << plane.spi << std::endl;
    std::cout << "Source: " << plane.source << std::endl;

    std::cout << "----------------------------------" << std::endl;
}

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

    std::string results = fetcher.fetchOpenSky();
    
    std::vector<AircraftState> planes = parser.parseOpenSky(results);
    for(int i = 0; i < 100; i++) {
        printPlane(planes[i]);
    }


    return 0;
}

