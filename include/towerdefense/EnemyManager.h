#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <iostream>
#include <vector>

#include <SFML/graphics.hpp>

#include <towerdefense/Enemy.h>
#include <towerdefense/ImageHandler.h>
#include <towerdefense/Tank.h>
#include <towerdefense/Map.h>

namespace towerdefense {

  class EnemyManager: public Entity
  {
  public :
    EnemyManager(int nombreEnemy,std::vector<std::vector<MapIdentifier>> level);
    virtual ~EnemyManager();
    void update(float dt);
    void render(sf::RenderWindow& window);

  private :
    std::vector<Enemy> allEnemy;
    std::vector<std::vector<MapIdentifier>> m_level;
  };
}
#endif
