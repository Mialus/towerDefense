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
    void nextLevel(int nombreEnemy, Map* iMap);

    void pause();
    bool m_enemiKilled;

  private :
    void addEnemy();

    std::vector<Enemy*> allEnemy;
    Map* m_map;
    int m_nbEnemy;
    int m_xStart;
    int m_yStart;
    float m_dtCumulated;
    bool m_paused;
  };
}
#endif
