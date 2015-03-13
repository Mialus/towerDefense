#include <towerdefense/EnemyManager.h>

namespace towerdefense {

  EnemyManager::EnemyManager(){}

  EnemyManager::EnemyManager(int nombreEnemy, Map* iMap){
    nextLevel(nombreEnemy, iMap);
  }

  void EnemyManager::nextLevel(int nombreEnemy, Map* iMap){
    m_nbEnemy = nombreEnemy;
    m_map = iMap;
    m_dtCumulated = 0;
    m_paused = false;
    m_enemiKilled = false;
    for(unsigned int i=0; i<iMap->getLevel().size(); ++i){
      std::vector<MapIdentifier> line = iMap->getLevel()[i];
      for(unsigned int j=0; j<line.size(); ++j){
        if(line[j]==MapIdentifier::START){
          m_xStart = i;
          m_yStart = j;
          if(nombreEnemy > 0){
            addEnemy();
            m_nbEnemy--;
          }
        }
      }
    }
  }

  void EnemyManager::update(float dt){
    if(!m_paused){
      m_dtCumulated += dt;
      if(m_nbEnemy > 0 && m_dtCumulated >= 1.5){
        addEnemy();
        m_nbEnemy--;
        m_dtCumulated = 0;
      }

      for(Enemy* enemy : allEnemy){
        if(enemy->GetLife() > 0){
          enemy->update(dt);
        } else {
          removeEnemy(enemy);
          m_enemiKilled = true;
        }
      }
    }
  }

  void EnemyManager::render(sf::RenderWindow& window){
    for(Enemy* enemy : allEnemy){
      enemy->render(window);
    }
  }

  void EnemyManager::clearEnemies(){
    allEnemy.clear();
  }

  std::vector<Enemy*>& EnemyManager::getAllEnemies(){
    return allEnemy;
  }

  void EnemyManager::removeEnemy(Enemy* e){
    allEnemy.erase(remove(allEnemy.begin(), allEnemy.end(), e), allEnemy.end());
  }

  void EnemyManager::addEnemy(){
    Enemy* e = new Tank(m_xStart,m_yStart);
    e->setCrossingPoints(m_map->getCrossingPoints());
    allEnemy.push_back(e);
  }

  void EnemyManager::pause(){
    m_paused = !m_paused;
  }

  EnemyManager::~EnemyManager(){}

}
