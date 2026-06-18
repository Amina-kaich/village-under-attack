#include "Building.h"

Building::Building(int sizeX, int sizeY, std::string repr, int costGold, int costElixir, int maxInstances, Position pos, int health)
    : sizeX(sizeX), sizeY(sizeY), repr(repr), costGold(costGold), costElixir(costElixir), maxInstances(maxInstances), position(pos), health(health) {}

int Building::getSizeX() const { return sizeX; }
int Building::getSizeY() const { return sizeY; }
std::string Building::getRepr() const { return repr; }
Position Building::getPosition() const { return position; }
int Building::getHealth() const { return health; }

bool Building::canPlace(const Resources& resources) const {
    return resources.gold >= costGold && resources.elixir >= costElixir;
    
  
}



void Building::takeDamage(int damage) {
    if (damage > 0) health -= damage;
    if (health < 0) health = 0;
}
