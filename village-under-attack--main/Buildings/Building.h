#ifndef BUILDING_H
#define BUILDING_H
#include "../Position.h"
#include "../Resources.h"
#include <string>

class Building {
protected:
    int sizeX;
    int sizeY;
    std::string repr;
    int costGold;
    int costElixir;
    int maxInstances;
    Position position;
    int health;

public:
    Building(int sizeX, int sizeY, std::string repr, int costGold, int costElixir, int maxInstances, Position pos, int health);
    virtual ~Building() = default;
    
    virtual bool collidesWith(Position checkPos) const {
        return (checkPos.x >= position.x && 
                checkPos.x < position.x + sizeX &&
                checkPos.y >= position.y && 
                checkPos.y < position.y + sizeY);
    }
    
    
 
 
    // Getters
    int getSizeX() const;
    int getSizeY() const;
    std::string getRepr() const;
    Position getPosition() const;
    int getHealth() const;

    // Methods
    virtual bool canPlace(const Resources& resources) const;
    virtual void takeDamage(int damage);
  
    
};

#endif
