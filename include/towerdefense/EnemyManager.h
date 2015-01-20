#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <iostream>
#include <vector>

#include <SFML/graphics.hpp>

#include <towerdefense/Enemy.h>
#include <towerdefense/ImageHandler.h>
#include "towerdefense/Tank.h"
#include <towerdefense/Map.h>

namespace towerdefense {

    class EnemyManager
{
    public :
    EnemyManager(int nombreEnemy,unsigned int tileW, unsigned int tileH, std::vector<std::vector<MapIdentifier>> level);
    virtual ~EnemyManager();
    void updateE(float dt);
    void render(sf::RenderWindow& window);

    private :
        std::vector<Enemy> allEnemy;
        std::vector<std::vector<MapIdentifier>> m_level;
        int m_nbrEnnemy;
        unsigned int m_tileWidth;
        unsigned int m_tileHeight;
};
}
#endif
