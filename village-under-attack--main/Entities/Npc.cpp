#include "Npc.h"

Npc::Npc(Position pos, std::string repr, int health)
    : Entity(pos, repr), health(health) {}

int Npc::getHealth() const { return health; }

void Npc::takeDamage(int damage) {
    if (damage > 0) health -= damage;
    if (health < 0) health = 0;
}
