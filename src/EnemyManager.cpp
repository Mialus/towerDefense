#include <towerdefense/EnemyManager.h>

namespace towerdefense {

  EnemyManager::EnemyManager(int nombreEnemy,std::vector<std::vector<MapIdentifier>> level){
    m_level=level;

    // Ajout des ennemies
    for(unsigned int i=0; i<level.size(); ++i){
      std::vector<MapIdentifier> line = level[i];
      for(unsigned int j=0; j<level.size(); ++j){
        if(line[j]==MapIdentifier::START){
          for(int nb=0; nb < nombreEnemy; nb++){
            allEnemy.push_back(Tank(i, j));
          }
        }
      }
    }
  }

  void EnemyManager::update(float dt){
    for(auto enemy : allEnemy){
      enemy.update(dt, m_level);
    }
  }

  void EnemyManager::render(sf::RenderWindow& window){
    for(auto enemy : allEnemy){
      enemy.render(window);
    }
  }

  EnemyManager::~EnemyManager(){}

}
