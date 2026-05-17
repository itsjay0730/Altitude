#include <iostream>
#include "telemetry/fetcher/Fetcher.hpp"

int main() {
    Fetcher fetcher;

    std::string results = fetcher.fetchOpenSky();
    std::cout << results << std::endl;
    
    return 0;
}

