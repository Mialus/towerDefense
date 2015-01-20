#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H

#include <iostream>
#include <vector>

#include <SFML/graphics.hpp>

#include <towerdefense/tower.h>
#include <towerdefense/ImageHandler.h>
#include "towerdefense/Tank.h"
#include <towerdefense/Map.h>

namespace towerdefense{

class TowerManager
{
    public:
        TowerManager(unsigned int tileWidth, unsigned int tileHeight);
        virtual ~TowerManager();
        void updateT(float dt);
        void render(sf::RenderWindow& window);
        void creatTower(tower t);
    private:
        std::vector<tower> allTower;
        unsigned int m_tileWidth;
        unsigned int m_tileHeight;
};
}
#endif // TOWERMANAGER_H
