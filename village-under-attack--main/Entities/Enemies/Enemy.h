// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include "NPC.h"
#include "Building.h"
class Enemy : public NPC {
protected:
    int damage;
    Building* target;
public:
    Enemy(Position pos, std::string repr, int health, int damage);
    void setTarget(Building* target);
    virtual void attack();
    virtual void moveTowardsTarget();
};
#endif
