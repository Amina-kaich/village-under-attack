#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Buildings/Building.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Enemies/Raider.h"
#include "Entities/Troops/Archer.h"

const int BOARD_WIDTH = 40;  // Adjust as needed
const int BOARD_HEIGHT = 30; // Adjust as needed

class Board {
private:
    int sizeX;
    int sizeY;
    std::vector<Building*> buildings;
    std::vector<Entity*> entities;
public:
    Board(int sizeX = 40, int sizeY = 30);
    ~Board();
    bool placeBuilding(Building* building, const Resources& resources);
    void placeEntity(Entity* entity);
    bool moveEntity(Entity* entity, int dx, int dy);
    void render() const;
    Building* findNearestBuilding(Position pos) const;
    std::vector<Building*>& getBuildings();  // Ensure this declaration is present
    std::vector<Entity*>& getEntities();     // Ensure this declaration is present
};

#endif
