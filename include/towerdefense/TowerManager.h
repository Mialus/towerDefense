#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H

#include <iostream>
#include <vector>

#include <towerdefense/Entity.h>
#include <towerdefense/tower.h>

namespace towerdefense{

  class TowerManager: public Entity {
    public:
        TowerManager();
        ~TowerManager();

        void update(float dt);
        void render(sf::RenderWindow& window);

        void addTower(float x, float y);
    private:
        std::vector<tower> allTower;
  };
}
#endif // TOWERMANAGER_H
