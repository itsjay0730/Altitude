#include <iostream>
#include <cpr/cpr.h>
#include "Fetcher.hpp"

std::string Fetcher::fetchOpenSky(){
    cpr::Response response = cpr::Get(cpr::Url{"https://opensky-network.org/api/states/all"});

    if(response.status_code == 200) {
        return response.text;
    }
    return "Error";
}