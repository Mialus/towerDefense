#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include <towerdefense/Map.h>
#include <towerdefense/Bullet.h>
#include <towerdefense/EnemyManager.h>
#include <towerdefense/Enemy.h>

namespace towerdefense{

  class Tower : public Entity {
  public :
    Tower(int level,int degat, float posX, float posY, EnemyManager* em);

    int getDegat();
    int getPosX();
    int getPosY();

    void update(float dt);
    void render(sf::RenderWindow& window);

  private :
    int m_level;
    int m_degat;
    int m_posX;
    int m_posY;
    std::vector<Bullet*> m_bullets;
    EnemyManager* m_emanager;
    float m_dt_cumulated;
  };

}

#endif // TOWER_H_INCLUDED
