#include "Entity.h"

Entity::Entity(Position pos, std::string repr) : position(pos), repr(repr) {}

Position Entity::getPosition() const { return position; }
std::string Entity::getRepr() const { return repr; }

void Entity::move(int dx, int dy) {
    position.x += dx;
    position.y += dy;
}
