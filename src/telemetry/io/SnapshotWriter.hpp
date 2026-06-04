#pragma once
#include <string>
#include <vector>
#include "../models/AircraftState.hpp"

class SnapshotWriter {
public:
    explicit SnapshotWriter(std::string outputPath);
    void writeAtomic(const std::vector<AircraftState>& aircraft) const;

private:
    std::string outputPath_;
};