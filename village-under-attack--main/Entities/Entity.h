#ifndef ENTITY_H
#define ENTITY_H
#include "../Position.h"
#include <string>

class Entity {
protected:
    Position position;
    std::string repr;

public:
    Entity(Position pos, std::string repr);
    virtual ~Entity() = default;

    // Getters
    Position getPosition() const;
    std::string getRepr() const;

    // Methods
    virtual void move(int dx, int dy);
};

#endif
