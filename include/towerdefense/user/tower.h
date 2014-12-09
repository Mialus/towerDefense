#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED
#include <SFML/Graphics.hpp>

#include <towerdefense/Entity.h>

namespace towerdefense{
  class Tower : public Entity {
public :
    Tower(int level,int degat, int posX, int posY, const char* m_image);
    void setLevel(int level);
    void setDegat(int degat,int level);
    void setPosX(int posX);
    void setPosY(int posY);
    sf::Sprite Show();
    void giveSprite();
    void setImage(const char* image);
    int getLevel();
    int getDegat();
    int getPosX();
    int getPosY();
    const char* getImage();

private :

    int m_level;
    int m_degat;
    int m_posX;
    int m_posY;
    const char* m_image;
    sf::Sprite m_sprite;
};
}

#endif // TOWER_H_INCLUDED
