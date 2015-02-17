#include <towerdefense/TowerManager.h>

namespace towerdefense{

  TowerManager::TowerManager(){}

  TowerManager::~TowerManager(){}

  bool TowerManager::alreadyTower(float x, float y){
    for(Tower t : allTower){
      if(x > t.getPosX() && x < t.getPosX()+ImageHandler::getTexture(SpriteList::TOWER).getSize().x
         && y > t.getPosY() && y < t.getPosY()+ImageHandler::getTexture(SpriteList::TOWER).getSize().y
         && x+ImageHandler::getTexture(SpriteList::TOWER).getSize().x > t.getPosX() && x+ImageHandler::getTexture(SpriteList::TOWER).getSize().x < t.getPosX()+ImageHandler::getTexture(SpriteList::TOWER).getSize().x
         && y+ImageHandler::getTexture(SpriteList::TOWER).getSize().y > t.getPosY() && y+ImageHandler::getTexture(SpriteList::TOWER).getSize().y < t.getPosY()+ImageHandler::getTexture(SpriteList::TOWER).getSize().y)
          return true;
    }
    return false;
  }

  void TowerManager::addTower(float x, float y, std::vector<std::vector<MapIdentifier>> level){
    std::vector<MapIdentifier> line = level[(int)(y/100)];
    std::vector<MapIdentifier> line_bot = level[(int)((y+ImageHandler::getTexture(SpriteList::TOWER).getSize().y)/100)];
    if(line[(int)(x/50)]==MapIdentifier::FIELD
       && line[(int)((x+ImageHandler::getTexture(SpriteList::TOWER).getSize().x)/50)]==MapIdentifier::FIELD
       && line_bot[(int)(x/50)]==MapIdentifier::FIELD
       && line_bot[(int)((x+ImageHandler::getTexture(SpriteList::TOWER).getSize().x)/50)]==MapIdentifier::FIELD
       && !alreadyTower(x,y)){
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

  void TowerManager::clearTowers(){
    allTower.clear();
  }

  int TowerManager::nbTowers(){
    return allTower.size();
  }
}
