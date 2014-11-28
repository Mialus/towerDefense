#ifndef ENNEMY_H_INCLUDED
#define ENNEMY_H_INCLUDED

class Ennemy
{
public:
    Ennemy();
    Ennemy(int speed,int life,int level,int coin);
    void SetSpeed(int speed);
    void SetLife(int life);
    void SetLevel(int level);
    void SetCoin(int coin);
    int GetSpeed();
    int GetLife();
    int GetLevel();
    int GetCoin();


private:
    int m_level;
    int m_life;
    int m_speed;
    int m_coin;

};

#endif // ENNEMY_H_INCLUDED
