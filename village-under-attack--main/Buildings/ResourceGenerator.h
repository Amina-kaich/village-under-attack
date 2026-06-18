#ifndef RESOURCEGENERATOR_H
#define RESOURCEGENERATOR_H
#include "Building.h"

class ResourceGenerator : public Building {
protected:
    int current;
    int capacity;
    bool isFull;

public:
    ResourceGenerator(int sizeX, int sizeY, std::string repr, int costGold, int costElixir, int maxInstances, Position pos, int health);
    virtual void generate(); // Generate resources over time
    virtual bool collect(Resources& resources); // Collect resources
    bool isFullGenerator() const;
};

#endif
