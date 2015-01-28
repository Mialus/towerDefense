#ifndef LEVELS_H
#define LEVELS_H

namespace towerdefense {
class Levels
{
    public:
        Levels(int life);
        virtual ~Levels();

    private:
        bool m_gameOver;
        int m_life;
};
}
#endif // LEVELS_H
