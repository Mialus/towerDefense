#ifndef LEVELS_H
#define LEVELS_H

#include <towerdefense/TowerManager.h>
#include <towerdefense/EnemyManager.h>
#include <towerdefense/Map.h>

namespace towerdefense {

  class Levels : public Entity
  {
      public:
          Levels(int life, TowerManager* iTMan, EnemyManager* iEMan, Map* m);
          virtual ~Levels();

          virtual void update(float dt);
          virtual void render(sf::RenderWindow& window);

          void changeLevel(int life);

      private:
          bool m_gameOver;
          int m_life;
          TowerManager* m_tMan;
          EnemyManager* m_eMan;
          Map* m_map;
  };
}
#endif // LEVELS_H
