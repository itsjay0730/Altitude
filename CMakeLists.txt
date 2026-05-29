cmake_minimum_required(VERSION 3.10) #require cmake v3.10+

project(Altitude) #proj name

set(CMAKE_CXX_STANDARD 20) #require c++20

find_package(cpr REQUIRED) #require the libraries
find_package(nlohmann_json REQUIRED)

add_executable(Altitude #compile into executable
    src/main.cpp
    src/telemetry/fetcher/Fetcher.cpp
    src/telemetry/parser/Parser.cpp
) 

target_link_libraries(Altitude PRIVATE #link the libraries
    cpr::cpr
    nlohmann_json::nlohmann_json
)