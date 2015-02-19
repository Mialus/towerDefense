#ifndef LEVELS_H
#define LEVELS_H

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>

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

          int getCoins();
          void winCoins(int coins);
          void cost(int coins);
          void changeLevel(int life);
          bool goodEnd();
          bool badEnd();
          bool isPaused();
          void pause();

      private:
          void drawString(sf::RenderWindow& window, const std::string str, int x, int y, int charsize=20);

          bool m_gameOver;
          bool m_paused;
          int m_life;
          int m_coins;
          TowerManager* m_tMan;
          EnemyManager* m_eMan;
          Map* m_map;
          sf::Font m_font;
  };
}
#endif // LEVELS_H
