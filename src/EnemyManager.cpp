#include <towerdefense/EnemyManager.h>

namespace towerdefense {

  EnemyManager::EnemyManager(){}

  Tank* EnemyManager::createPTank(unsigned int i, unsigned int j){
    Tank* tank = new Tank(i,j);
    return tank;
  }

  EnemyManager::EnemyManager(int nombreEnemy, Map* iMap){
    // Ajout des ennemies
    for(unsigned int i=0; i<iMap->getLevel().size(); ++i){
      std::vector<MapIdentifier> line = iMap->getLevel()[i];
      for(unsigned int j=0; j<line.size(); ++j){
        if(line[j]==MapIdentifier::START){
          for(int nb=0; nb < nombreEnemy; nb++){
            allEnemy.push_back(createPTank(i,j));
          }
        }
      }
    }
  }

  void EnemyManager::update(float dt){
    for(Enemy* enemy : allEnemy){
      enemy->update(dt);
      std::cout << "Pos enemy (" << enemy->GetId() << ") : " << enemy->GetPosX() << "," << enemy->GetPosY() << std::endl;
    }
  }

  void EnemyManager::render(sf::RenderWindow& window){
    for(Enemy* enemy : allEnemy){
      enemy->render(window);
    }
  }

  void EnemyManager::clearEnemies(){
    allEnemy.clear();
    Enemy::resetIds();
  }

  std::vector<Enemy*>& EnemyManager::getAllEnemies(){
    return allEnemy;
  }

  void EnemyManager::removeEnemy(Enemy* e){
    allEnemy.erase(remove(allEnemy.begin(), allEnemy.end(), e), allEnemy.end());
  }

  EnemyManager::~EnemyManager(){}

}
