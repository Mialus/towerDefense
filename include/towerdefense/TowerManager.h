#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H

#include <iostream>
#include <vector>

#include <towerdefense/Entity.h>
#include <towerdefense/Tower.h>
#include <towerdefense/Map.h>

namespace towerdefense{

  class TowerManager: public Entity {
    public:
        TowerManager();
        ~TowerManager();

        void update(float dt);
        void render(sf::RenderWindow& window);

        void addTower(float x, float y, std::vector<std::vector<MapIdentifier>> level);
        void clearTowers();
        int nbTowers();
    private:
        bool alreadyTower(float x, float y);

        std::vector<Tower> allTower;
  };
}
#endif // TOWERMANAGER_H
