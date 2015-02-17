#include <towerdefense/Levels.h>

namespace towerdefense {

  Levels::Levels(int life, TowerManager* iTMan, EnemyManager* iEMan, Map* m)
  {
      m_life=life;
      m_gameOver=false;
      m_tMan = iTMan;
      m_eMan = iEMan;
      m_map = m;
      m_coins = 10000;
  }

  Levels::~Levels(){
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
  }

  void Levels::update(float dt){
// TODO (Erizino#1#): Check Enemy position in levels update function
std::cout << "Life : " << m_life << std::endl;
std::cout << "GameOver : " << m_gameOver << std::endl;
    std::vector<Enemy*> enemies = m_eMan->getAllEnemies();
    for(Enemy* enemy : enemies){
      if(enemy->GetPosX() >= m_map->getEnd()->getX()-0.1 && enemy->GetPosY() <= m_map->getEnd()->getY()+0.1
         && enemy->GetPosY() >= m_map->getEnd()->getY()-0.1 && enemy->GetPosY() <= m_map->getEnd()->getY()+0.1){
        m_life--;
        m_eMan->removeEnemy(enemy);
      }
    }
    if(m_life <= 0){
      m_gameOver = true;
    }
  }

  bool Levels::goodEnd(){
    return m_eMan->getAllEnemies().size() == 0;
  }

  bool Levels::badEnd(){
    return m_gameOver;
  }

  void Levels::render(sf::RenderWindow& window){}

  void Levels::changeLevel(int life){
    m_life=life;
    m_gameOver=false;
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
  }
}
