#include <towerdefense/Map.h>

namespace towerdefense {

  Map::Map(){
  }

  Map::~Map(){
  }

  void Map::update(float dt){
  }

  void Map::render(sf::RenderWindow& window){
    sf::Sprite sprite;

    for(unsigned int i=0; i<m_level.size(); ++i){
      std::vector<MapIdentifier> line = m_level[i];
      for(unsigned int j=0; j<line.size(); ++j){
        switch(line[j]){
        case MapIdentifier::FIELD:
          sprite = ImageHandler::getSprite(SpriteList::FIELD);
          break;
        case MapIdentifier::START:
          sprite = ImageHandler::getSprite(SpriteList::START);
          break;
        case MapIdentifier::END:
          sprite = ImageHandler::getSprite(SpriteList::END);
          break;
        case MapIdentifier::PATH:
          sprite = ImageHandler::getSprite(SpriteList::PATH);
          break;
        default:
          sprite = ImageHandler::getSprite(SpriteList::FIELD);
          break;
        }
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
        window.draw(sprite);
      }
    }
  }

  void Map::setWidth(int width){
    if(width > 0) {
      m_width = width;
      m_tileWidth = width/10;
    }
  }

  void Map::setHeight(int height){
    if(height > 0) {
      m_height = height;
      m_tileHeight = height/10;
    }
  }

  void Map::setLevel(std::vector<std::vector<MapIdentifier>> level){
    m_level = level;
  }

}
