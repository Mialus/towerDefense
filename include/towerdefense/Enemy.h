#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED

#include <boost/filesystem.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>

#include <towerdefense/World.h>
#include <towerdefense/Entity.h>
#include <towerdefense/Map.h>

namespace towerdefense {

  class Enemy : public Entity {
  public:
    Enemy(int speed,int life,int level,int coin,int defense, float posX, float posY);
    ~Enemy();
    void SetDefense(int defense,int level);
    void update(float dt);
    void render(sf::RenderWindow& window);
    void SetSpeed(int speed);
    void SetLife(int life);
    void SetLevel(int level);
    void SetPosX(int pos);
    void SetPosY(int posY);
    void SetPosXb(int pos);
    void SetPosYb(int posY);
    void SetCoin(int coin);
    void setCrossingPoints(const std::vector<CrossingPoint*> crossingPoints);
    int GetDefense();
    int GetSpeed();
    int GetLife();
    int GetPosX();
    int GetPosY();
    int GetPosXb();
    int GetPosYb();
    int GetLevel();
    int GetCoin();
    int GetId();
    static void resetIds();

  protected:
    static int m_current_id;
    int m_id;
    int m_defense;
    int m_level;
    int m_life;
    int m_speed;
    int m_coin;
    float m_posX;
    float m_posY;
    float m_posXb;
    float m_posYb;
    std::vector<CrossingPoint*> m_crossingPoints;
  };

}

#endif // ENNEMY_H_INCLUDED
