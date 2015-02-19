#ifndef ANTICHAR_H
#define ANTICHAR_H

#include "Tower.h"

namespace towerdefense{

class AntiChar : Tower
{
    public:
        AntiChar(int posX, int posY, EnemyManager* em) : Tower(1,20,posX,posY, em){}
        virtual ~AntiChar();
};
}
#endif // ANTICHAR_H
