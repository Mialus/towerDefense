#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <towerdefense/Entity.h>

namespace towerdefense{

  class tower : public Entity {
  public :
    tower(int level,int degat, int posX, int posY);
    void setLevel(int level);
    void setDegat(int degat,int level);
    void setPosX(int posX);
    void setPosY(int posY);
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
  };

}

#endif // TOWER_H_INCLUDED
