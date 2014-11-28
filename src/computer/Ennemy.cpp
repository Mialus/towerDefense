#include "Ennemy.h"

void Ennemy::SetCoin(int coin)
{
    m_coin=coin;
}

void Ennemy::SetLevel(int level)
{
    m_level=level;
}

void Ennemy::SetLife(int life)
{
    m_life=life;
}

void Ennemy::SetSpeed(int speed)
{
    m_speed=speed;
}

int Ennemy::GetCoin()
{
    return m_coin;
}

int Ennemy::GetLevel()
{
    return m_level;
}

int Ennemy::GetLife()
{
    return m_life;
}

int Ennemy::GetSpeed()
{
    return m_speed;
}

Ennemy::Ennemy()
{
    Ennemy::SetLife(50);
    Ennemy::SetSpeed(1);
    Ennemy::SetLevel(1);
    Ennemy::SetCoin(20);
}

Ennemy::Ennemy(int speed,int life,int level,int coin)
{
    Ennemy::SetLife(life);
    Ennemy::SetSpeed(speed);
    Ennemy::SetLevel(level);
    Ennemy::SetCoin(coin);
}

