#include <towerdefense/TowerManager.h>

namespace towerdefense{

  TowerManager::TowerManager(EnemyManager* em){
    m_emanager = em;
  }

  TowerManager::~TowerManager(){}

  bool TowerManager::alreadyTower(float x, float y){
    unsigned int width_tower = ImageHandler::getTexture(SpriteList::TOWER).getSize().x;
    unsigned int height_tower = ImageHandler::getTexture(SpriteList::TOWER).getSize().y;
    float x_bot = x+width_tower;
    float y_bot = y+height_tower;
    for(Tower* t : allTower){
      if(  (x > t->getPosX()
         && x < t->getPosX()+width_tower
         && y > t->getPosY()
         && y < t->getPosY()+height_tower)
         ||(x > t->getPosX()
         && x < t->getPosX()+width_tower
         && y_bot > t->getPosY()
         && y_bot < t->getPosY()+height_tower)
         ||(x_bot > t->getPosX()
         && x_bot < t->getPosX()+width_tower
         && y > t->getPosY()
         && y < t->getPosY()+height_tower)
         ||(x_bot > t->getPosX()
         && x_bot < t->getPosX()+width_tower
         && y_bot > t->getPosY()
         && y_bot < t->getPosY()+height_tower))
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
      allTower.push_back(new Tower(1, 50, x, y, m_emanager));
    }
  }

  void TowerManager::update(float dt){
    for(Tower* t : allTower){
      t->update(dt);
    }
  }

  void TowerManager::render(sf::RenderWindow& window){
    for(Tower* t : allTower){
      t->render(window);
    }
  }

  void TowerManager::clearTowers(){
    allTower.clear();
  }

  int TowerManager::nbTowers(){
    return allTower.size();
  }
}
