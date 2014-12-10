#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <towerdefense/Entity.h>

namespace towerdefense {

  class Bullet : public Entity {
  public :
    void setPosX(float posX);
    void setPosY(float posY);
    void setSpeedX(float speX);
    void setSpeedY(float speY);
    void setTaille(int tai);
    float getPosX();
    float getPosY();
    float getSpeedX();
    float getSpeedY();
    int getTaille();

  private :
     float m_posX;
     float m_posY;
     float m_speedX;
     float m_speedY;
     int m_Taille;
  };

}

#endif
