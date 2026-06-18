#include "Resources.h"

Resources::Resources(int gold, int elixir) : gold(gold), elixir(elixir) {}

void Resources::addGold(int amount) {
    if (amount > 0) gold += amount;
}

void Resources::addElixir(int amount) {
    if (amount > 0) elixir += amount;
}

bool Resources::consumeGold(int amount) {
    if (amount >= 0 && gold >= amount) {
        gold -= amount;
        return true;
    }
    return false;
}

bool Resources::consumeElixir(int amount) {
    if (amount >= 0 && elixir >= amount) {
        elixir -= amount;
        return true;
    }
    return false;
}
