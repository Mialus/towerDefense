#include <towerdefense/Levels.h>

namespace towerdefense {

  Levels::Levels(int life, TowerManager* iTMan, EnemyManager* iEMan, Map* m)
  {
      m_life=life;
      m_gameOver=false;
      m_tMan = iTMan;
      m_eMan = iEMan;
      m_map = m;
  }

  Levels::~Levels(){
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
  }

  void Levels::update(float dt){
    // TODO CHECK ENEMIES POSITION
    std::cout << "Nb Towers : " << m_tMan->nbTowers() << std::endl;
    std::vector<Enemy> enemies = m_eMan->getAllEnemies();
    for(auto enemy : enemies){
      std::cout << "Pos Enemies : " << enemy.GetPosX() << "," << enemy.GetPosY() << std::endl;
    }
  }

  void Levels::render(sf::RenderWindow& window){}

  void Levels::changeLevel(int life){
    m_life=life;
    m_gameOver=false;
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
  }
}
