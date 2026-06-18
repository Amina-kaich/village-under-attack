#ifndef NPC_H
#define NPC_H
#include "Entity.h"

class Npc : public Entity {
protected:
    int health;

public:
    Npc(Position pos, std::string repr, int health);
    int getHealth() const;
    void takeDamage(int damage);
};

#endif
