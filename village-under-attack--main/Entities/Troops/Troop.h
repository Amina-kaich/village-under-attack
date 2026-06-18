// Troop.h
#ifndef TROOP_H
#define TROOP_H
#include "Npc.h"
class Troop : public NPC {
protected:
    int damage;
    int attackRange;
public:
    Troop(Position pos, std::string repr, int health, int damage, int attackRange);
    virtual void attack(Entity* target);
};
#endif
