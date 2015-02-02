#include <towerdefense/EnemyManager.h>

namespace towerdefense {

  EnemyManager::EnemyManager(){}

  EnemyManager::EnemyManager(int nombreEnemy,std::vector<std::vector<MapIdentifier>> level){
    m_level=level;

    // Ajout des ennemies
    for(unsigned int i=0; i<level.size(); ++i){
      std::vector<MapIdentifier> line = level[i];
      for(unsigned int j=0; j<line.size(); ++j){
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

  void EnemyManager::clearEnemies(){
    allEnemy.clear();
    Enemy::resetIds();
  }

  std::vector<Enemy> EnemyManager::getAllEnemies(){
    return allEnemy;
  }

  void EnemyManager::removeEnemy(Enemy e){
    std::vector<Enemy>::iterator it = allEnemy.begin();
    while(it < allEnemy.size()){
      if(allEnemy.at(it).GetId() == e.GetId()){
        allEnemy.erase(it);
      }
    }
  }

  EnemyManager::~EnemyManager(){}

}
