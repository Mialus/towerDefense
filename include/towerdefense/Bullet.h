#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <towerdefense/Entity.h>
#include <SFML/Graphics.hpp>

#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include <towerdefense/Map.h>
namespace towerdefense {

  class Bullet : public Entity {
  public :
    Bullet(float posX,float posY, float posCX, float posCY);
    void update(float dt);
    void render(sf::RenderWindow& window);

  private :
     float m_posX;
     float m_posY;
     float m_posCX;// position de la cible
     float m_posCY;
     float m_speedX;
     float m_speedY;
     int m_Taille;
  };

}

#endif
