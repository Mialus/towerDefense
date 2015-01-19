#ifndef ANTICHAR_H
#define ANTICHAR_H

#include "tower.h"
namespace towerdefense{

class AntiChar : tower
{
    public:
        AntiChar(int posX, int posY) : tower(1,20,posX,posY){}
        virtual ~AntiChar();
};
}
#endif // ANTICHAR_H
