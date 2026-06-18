#include "ResourceGenerator.h"

ResourceGenerator::ResourceGenerator(int sizeX, int sizeY, std::string repr, int costGold, int costElixir, int maxInstances, Position pos, int health)
    : Building(sizeX, sizeY, repr, costGold, costElixir, maxInstances, pos, health), current(0), capacity(100), isFull(false) {}

void ResourceGenerator::generate() {
    if (!isFull) {
        current += 10; // Generate 10 units per cycle (adjust as needed)
        if (current >= capacity) {
            current = capacity;
            isFull = true;
        }
    }
}

bool ResourceGenerator::collect(Resources& resources) {
    if (current > 0) {
        resources.addGold(current); // Default for GoldMine; overridden for ElixirCollector
        current = 0;
        isFull = false;
        return true;
    }
    return false;
}

bool ResourceGenerator::isFullGenerator() const {
    return isFull;
}
