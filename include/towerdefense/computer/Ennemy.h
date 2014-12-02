#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED

#include <sfml/Graphics.hpp>
#include <sfml/Window.hpp>
#include <towerdefense/World.h>
#include "../src/bin/config.h.in"

class Ennemy
{
public:

    Ennemy(int speed,int life,int level,int coin,const char* image, int defense);
    void SetDefense(int defense,int level);
    void SetSpeed(int speed);
    void SetLife(int life);
    void SetLevel(int level);
    void SetCoin(int coin);
    void SetImage(const char* image);
    int getDefense();
    int GetSpeed();
    int GetLife();
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
    const char* m_image;
};

#endif // ENNEMY_H_INCLUDED
