#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include <towerdefense/Map.h>
#include <towerdefense/Bullet.h>

namespace towerdefense{

  class Tower : public Entity {
  public :
    Tower(int level,int degat, float posX, float posY);
    void setLevel(int level);
    void setDegat(int degat,int level);
    void setPosX(int posX);
    void setPosY(int posY);
    void render(sf::RenderWindow& window);
    int getLevel();
    int getDegat();
    int getPosX();
    int getPosY();
    void update(float dt);

  private :
    int m_level;
    int m_degat;
    int m_posX;
    int m_posY;
    std::vector<Bullet> bul;
  };

}

#endif // TOWER_H_INCLUDED
