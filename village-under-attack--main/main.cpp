#include "Board.h"
#include "Buildings/TownHall.h"  // Fixed path
#include "Buildings/GoldMine.h"
#include "Buildings/ElixirCollector.h"
#include "Buildings/Wall.h"
#include "Entities/Player.h"
#include "Entities/Enemies/Raider.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    Board board;

    Player* player = new Player(Position(1, 1));
    board.placeEntity(player);
    board.placeBuilding(new TownHall(Position(10, 10)), player->getResources());

    bool running = true;
    int enemySpawnTimer = 0;
    while (running) {
        board.render();
        std::cout << "Move (arrows: w/a/s/d), Build (G/E/W), Collect (C),Quit (Q): ";

        char input;
        std::cin >> input;

        switch (tolower(input)) {
            case 'w': board.moveEntity(player,0,1); break;
            case 's': board.moveEntity(player,0,-1); break;
            case 'a': board.moveEntity(player,-1,0); break;
            case 'd': board.moveEntity(player,1,0); break;
            case 'g': {
                GoldMine* mine = new GoldMine(player->getPosition());
                if (board.placeBuilding(mine, player->getResources())) {
                    player->getResources().consumeElixir(100);
                } else {
                    delete mine;
                }
                break;
            }
            case 'e': {
                ElixirCollector* collector = new ElixirCollector(player->getPosition());
                if (board.placeBuilding(collector, player->getResources())) {
                    player->getResources().consumeGold(100);
                } else {
                    delete collector;
                }
                break;
            }
            case 'v': {
                Wall* wall = new Wall(player->getPosition());
                if (board.placeBuilding(wall, player->getResources())) {
                    player->getResources().consumeGold(10);
                } else {
                    delete wall;
                }
                break;
            }
            case 'c': {
                for (Building* b : board.getBuildings()) {
                    ResourceGenerator* rg = dynamic_cast<ResourceGenerator*>(b);
                    if (rg && rg->getPosition() == player->getPosition()) {
                        player->collectResources(rg);
                    }
                }
                break;
    
            }
            case 'q': running = false; break;
        }

        for (Building* b : board.getBuildings()) {
            ResourceGenerator* rg = dynamic_cast<ResourceGenerator*>(b);
            if (rg) rg->generate();
        }

        if (++enemySpawnTimer >= 50) {
            board.placeEntity(new Raider(Position(rand() % 20, rand() % 20)));
            enemySpawnTimer = 0;
        }

        for (Entity* e : board.getEntities()) {
            Raider* raider = dynamic_cast<Raider*>(e);
            if (raider) {
                Building* target = board.findNearestBuilding(raider->getPosition());
                if (target) {
                    Position tp = target->getPosition();
                    Position ep = raider->getPosition();
                    int dx = (tp.x > ep.x) ? 1 : (tp.x < ep.x) ? -1 : 0;
                    int dy = (tp.y > ep.y) ? 1 : (tp.y < ep.y) ? -1 : 0;
                    board.moveEntity(raider, dx, dy);
                    if (raider->getPosition() == target->getPosition()) {
                        target->takeDamage(10);
                    }
                }
            }
        }

        for (Building* b : board.getBuildings()) {
            if (dynamic_cast<TownHall*>(b) && b->getHealth() <= 0) {
                std::cout << "TownHall destroyed! Game Over!" << std::endl;
                running = false;
            }
        }
    }

    return 0;
}
