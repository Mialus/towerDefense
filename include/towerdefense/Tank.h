#ifndef TANK_H
#define TANK_H

#include "Enemy.h"
namespace towerdefense {

class Tank : public Enemy
{
    public:
        Tank(int posX, int posY) : Enemy(1,150,1,10,2,posX,posY){}
        virtual ~Tank();
    private:
};
}

#endif // TANK_H
