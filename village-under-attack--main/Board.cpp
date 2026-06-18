#include "Board.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Buildings/ResourceGenerator.h"
#include "Buildings/GoldMine.h"
#include "Buildings/ElixirCollector.h"

Board::Board(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {}

Board::~Board() {
    for (Building* b : buildings) delete b;
    for (Entity* e : entities) delete e;



}

bool Board::placeBuilding(Building* building, const Resources& resources) {

    Position pos = building->getPosition();
    
    // Boundary check
    if (pos.x < 0 || pos.x >= sizeX || 
        pos.y < 0 || pos.y >= sizeY) {
        return false;
    }
    
    // ... (rest of your existing placement logic)
    if (building->canPlace(resources)) {
        buildings.push_back(building);
        return true;
    }
    return false;
}

void Board::placeEntity(Entity* entity) {
    entities.push_back(entity);
}

bool Board::moveEntity(Entity* entity, int dx, int dy) {
    Position current = entity->getPosition();
    Position newPos(current.x + dx, current.y + dy); 

    std::cout << "Attempting to move from (" << current.x << "," << current.y 
              << ") to (" << newPos.x << "," << newPos.y << ")\n";

    // Boundary check
    if (newPos.x < 0 || newPos.x >= sizeX || newPos.y < 0 || newPos.y >= sizeY) {
        std::cout << "Movement blocked by boundary\n";
        return false;
    }

    // Only move if not blocked
    entity->move(dx,dy);
    std::cout << "Movement successful to (" 
              << entity->getPosition().x << "," 
              << entity->getPosition().y << ")\n";
    return true;
}


Building* Board::findNearestBuilding(Position pos) const {
    Building* nearest = nullptr;
    double minDist = std::numeric_limits<double>::max();
    for (Building* b : buildings) {
        Position bp = b->getPosition();
        double dist = std::sqrt(std::pow(bp.x - pos.x, 2) + std::pow(bp.y - pos.y, 2));
        if (dist < minDist) {
            minDist = dist;
            nearest = b;
        }
    }
    return nearest;
}

std::vector<Building*>& Board::getBuildings() {
    return buildings;
}

std::vector<Entity*>& Board::getEntities() {
    return entities;
}
void Board::render() const {
    // Create grid with empty spaces instead of dots
    std::vector<std::vector<std::string>> grid(sizeY, std::vector<std::string>(sizeX, " "));

    // Original building rendering (unchanged)
    for (Building* b : buildings) {
        Position pos = b->getPosition();
        std::string repr = b->getRepr();
        ResourceGenerator* rg = dynamic_cast<ResourceGenerator*>(b);
        if (rg && rg->isFullGenerator()) {
            if (dynamic_cast<GoldMine*>(b)) repr = "🪙";
            else if (dynamic_cast<ElixirCollector*>(b)) repr = "🧴";
        }
        for (int y = pos.y; y < pos.y + b->getSizeY() && y < sizeY; ++y) {
            for (int x = pos.x; x < pos.x + b->getSizeX() && x < sizeX; ++x) {
                grid[y][x] = repr;
            }
        }
    }

   for (Entity* e : entities) {
        Position pos = e->getPosition();
        if (pos.x >= 0 && pos.x < sizeX && pos.y >= 0 && pos.y < sizeY) {
            grid[pos.y][pos.x] = e->getRepr(); 
		}
	}
    // Add top border
    std::cout << "+";
    for (int x = 0; x < sizeX ; ++x) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    // Print grid with side borders
    for (const auto& row : grid) {
        std::cout << "|"; // Left border
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\b|" << std::endl; // Right border and remove trailing space
    }

    // Add bottom border
    std::cout << "+";
    for (int x = 0; x < sizeX ; ++x) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    // Original resource display (unchanged)
    Player* player = nullptr;
    for (Entity* e : entities) {
        if (dynamic_cast<Player*>(e)) {
            player = dynamic_cast<Player*>(e);
            break;
        }
    }
    if (player) {
        std::cout << "Gold: " << player->getResources().gold
                  << " Elixir: " << player->getResources().elixir << std::endl;
    }
   }
