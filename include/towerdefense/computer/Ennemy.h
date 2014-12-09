#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include "../src/bin/config.h.in"
#include <boost/filesystem.hpp>

namespace towerdefense {

class Ennemy : public Entity {
public:

    Ennemy(int speed,int life,int level,int coin,const char* image, int defense, int posX, int posY);
    void SetDefense(int defense,int level);
    void SetSpeed(int speed);
    void SetLife(int life);
    void SetLevel(int level);
    void giveSprite();
    void SetPosX(int pos);
    void SetPosY(int posY);
    void SetPosXb(int pos);
    void SetPosYb(int posY);
    void SetCoin(int coin);
    void SetImage(const char* image);
    int getDefense();
    int GetSpeed();
    int GetLife();
    int getPosX();
    int getPosY();
    int getPosXb();
    int getPosYb();
    int GetLevel();
    int GetCoin();
    const char* GetImage();
    sf::Sprite Show();


private:
    int m_defense;
    int m_level;
    int m_life;
    int m_speed;
    int m_coin;
    int m_posX;
    int m_posY;
    const char* m_image;
    sf::Sprite m_sprite;
    int m_posXb;
    int m_posYb;
};
}

#endif // ENNEMY_H_INCLUDED
