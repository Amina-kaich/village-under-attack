#include "Wall.h"

Wall::Wall(Position pos)
    : Building(1, 1, "🚧", 10, 0, 200, pos, 300) {} // Size 1x1, emoji 🚧, 10 gold, max 200, 300 health
