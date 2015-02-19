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
    Enemy(int speed,int life,int coin,int defense, float posX, float posY);
    ~Enemy();

    void update(float dt);
    void render(sf::RenderWindow& window);

    void setCrossingPoints(const std::vector<CrossingPoint*> crossingPoints);

    int GetDefense();
    float GetSpeed();
    int GetLife();
    float GetPosX();
    float GetPosY();
    int GetCoin();
    void loseLife(int life);

    bool endCorssingPoints();

  protected:
    int m_defense;
    int m_life;
    float m_speed;
    int m_coin;
    float m_posX;
    float m_posY;
    float m_posXb;
    float m_posYb;
    std::vector<CrossingPoint*> m_crossingPoints;
    char m_currentCp;
  };

}

#endif // ENNEMY_H_INCLUDED
