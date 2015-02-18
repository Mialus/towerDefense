#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include <towerdefense/Map.h>
#include <towerdefense/Enemy.h>

namespace towerdefense {

  class Bullet : public Entity {
  public :
    Bullet(float posX,float posY, Enemy* e);
    void update(float dt);
    void render(sf::RenderWindow& window);

    float getX();
    float getY();
    Enemy* getCible();

  private :
     float m_posX;
     float m_posY;
     Enemy* m_cible;
  };

}

#endif
