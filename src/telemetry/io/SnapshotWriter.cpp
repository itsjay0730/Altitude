#include "SnapshotWriter.hpp"
#include <ctime>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdexcept>

using nlohmann::json;

SnapshotWriter::SnapshotWriter(std::string outputPath)
    : outputPath_(std::move(outputPath)) {}

void SnapshotWriter::writeAtomic(const std::vector<AircraftState>& aircraft) const {
    json payload;
    payload["generated_at"] = std::time(nullptr);
    payload["count"] = aircraft.size();
    payload["aircraft"] = json::array();

    for (const auto& a : aircraft) {
        payload["aircraft"].push_back({
            {"icao24", a.icao24},
            {"callsign", a.callsign},
            {"originCountry", a.originCountry},
            {"time", a.time},
            {"lastContact", a.lastContact},
            {"longitude", a.longitude},
            {"latitude", a.latitude},
            {"altitude", a.altitude},
            {"velocity", a.velocity},
            {"direction", a.direction},
            {"altitudeRate", a.altitudeRate},
            {"inAir", a.inAir},
            {"squawk", a.squawk},
            {"spi", a.spi},
            {"source", a.source}
        });
    }

    std::filesystem::path finalPath(outputPath_);
    std::filesystem::create_directories(finalPath.parent_path());

    std::filesystem::path tempPath = finalPath;
    tempPath += ".tmp";

    {
        std::ofstream out(tempPath, std::ios::trunc);
        if (!out) throw std::runtime_error("Failed to open temp snapshot file");
        out << payload.dump();
        if (!out.good()) throw std::runtime_error("Failed writing temp snapshot file");
    }

    if (std::filesystem::exists(finalPath)) {
        std::filesystem::remove(finalPath);
    }
    std::filesystem::rename(tempPath, finalPath);
}