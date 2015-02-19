#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H

#include <iostream>
#include <vector>

#include <towerdefense/Entity.h>
#include <towerdefense/Tower.h>
#include <towerdefense/Map.h>
#include <towerdefense/EnemyManager.h>

namespace towerdefense{

  class TowerManager: public Entity {
    public:
        TowerManager(EnemyManager* em);
        ~TowerManager();

        void update(float dt);
        void render(sf::RenderWindow& window);

        bool addTower(float x, float y, const std::vector<std::vector<MapIdentifier>> level);
        void clearTowers();

        void pause();

    private:
        bool alreadyTower(float x, float y);

        std::vector<Tower*> allTower;
        EnemyManager* m_emanager;
        bool m_paused;
  };
}
#endif // TOWERMANAGER_H
