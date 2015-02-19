#ifndef TANK_H
#define TANK_H

#include "Enemy.h"
namespace towerdefense {

class Tank : public Enemy
{
    public:
      Tank(int posX, int posY) : Enemy(1,150,10,2,posX,posY){}
      virtual ~Tank();

      void render(sf::RenderWindow& window);

    private:
};
}

#endif // TANK_H
