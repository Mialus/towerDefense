#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <iostream>
#include <vector>

#include <SFML/graphics.hpp>

#include <towerdefense/Enemy.h>
#include <towerdefense/ImageHandler.h>
#include <towerdefense/Tank.h>
#include <towerdefense/Map.h>
#include <towerdefense/CrossingPoint.h>

namespace towerdefense {

  class EnemyManager: public Entity
  {
  public :
    EnemyManager();
    EnemyManager(int nombreEnemy, Map* iMap);
    virtual ~EnemyManager();
    void update(float dt);
    void render(sf::RenderWindow& window);
    void clearEnemies();
    std::vector<Enemy*>& getAllEnemies();
    void removeEnemy(Enemy* e);

  private :
    std::vector<Enemy*> allEnemy;
  };
}
#endif
