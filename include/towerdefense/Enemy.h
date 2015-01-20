#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED

#include <boost/filesystem.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>

#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include <towerdefense/MapIdentifier.h>

namespace towerdefense {

  class Enemy : public Entity {
  public:
    Enemy(int speed,int life,int level,int coin,int defense);
    ~Enemy();
    void SetDefense(int defense,int level);
    void update(float dt, std::vector<std::vector<MapIdentifier>> level);
    void SetSpeed(int speed);
    void SetLife(int life);
    void SetLevel(int level);
    void SetPosX(int pos);
    void SetPosY(int posY);
    void SetPosXb(int pos);
    void SetPosYb(int posY);
    void SetCoin(int coin);
    int GetDefense();
    int GetSpeed();
    int GetLife();
    int GetPosX();
    int GetPosY();
    int GetPosXb();
    int GetPosYb();
    int GetLevel();
    int GetCoin();

  private:
    int m_defense;
    int m_level;
    int m_life;
    int m_speed;
    int m_coin;
    int m_posX=-5;
    int m_posY=-5;
    int m_posXb=-5;
    int m_posYb=-5;
  };

}

#endif // ENNEMY_H_INCLUDED
