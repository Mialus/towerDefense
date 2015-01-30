#include <towerdefense/TowerManager.h>

namespace towerdefense{

  TowerManager::TowerManager(){}

  TowerManager::~TowerManager(){}

  void TowerManager::addTower(float x, float y, std::vector<std::vector<MapIdentifier>> level){

    std::vector<MapIdentifier> line = level[(int)(y/100)];
    if(line[(int)(x/50)]==MapIdentifier::FIELD){
    Tower t(1, 50, x, y);
    allTower.push_back(t);
    }
  }

  void TowerManager::update(float dt){
    for(auto t : allTower){
      t.update(dt);
    }
  }

  void TowerManager::render(sf::RenderWindow& window){
    for(auto t : allTower){
      t.render(window);
    }
  }
}
