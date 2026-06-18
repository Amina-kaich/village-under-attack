#include "TownHall.h"

TownHall::TownHall(Position pos)
    : Building(5, 5, "🏡", 0, 0, 1, pos, 1000) {} // Size 5x5, emoji 🏡, no cost, max 1, 1000 health
