cmake_minimum_required(VERSION 3.10) #require cmake v3.10+

project(Altitude) #proj name

set(CMAKE_CXX_STANDARD 17) #require c++17 

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

target_link_libraries(Altitude PRIVATE cpr::cpr)

add_executable(Altitude src/main.cpp) #compile main.cpp into executable