#include <towerdefense/Map.h>

namespace towerdefense {

  Map::Map(std::string levelpath){
    std::ifstream levelTxt(levelpath);
    std::string line;
    m_level = std::vector<std::vector<MapIdentifier>>();

    setWidth(500);
    setHeight(500);

    // Loading text file for level definition
    if (levelTxt.is_open())
    {
      while(getline(levelTxt,line))
      {
        int j=0;
        m_level.push_back(std::vector<MapIdentifier>());
        for(int i=0; i<line.length(); i++){
          switch(line[i]){
          case '#':
            m_level.at(j).push_back(MapIdentifier::FIELD);
            break;
          case 'D':
            m_level.at(j).push_back(MapIdentifier::START);
            break;
          case 'A':
            m_level.at(j).push_back(MapIdentifier::END);
            break;
          case '.':
            m_level.at(j).push_back(MapIdentifier::PATH);
            break;
          default:
            m_level.at(j).push_back(MapIdentifier::FIELD);
            break;
          }
        }
        j++;
      }
      levelTxt.close();
    }
    else {
      std::cout << "Unable to open file";
    }

    m_sprites = std::vector<sf::Sprite>();
    m_sprites.push_back(sf::Sprite());
    m_sprites.at(0).setTexture(ImageHandler::getTexture(SpriteList::FIELD));
    m_sprites.push_back(sf::Sprite());
    m_sprites.at(1).setTexture(ImageHandler::getTexture(SpriteList::START));
    m_sprites.push_back(sf::Sprite());
    m_sprites.at(2).setTexture(ImageHandler::getTexture(SpriteList::END));
    m_sprites.push_back(sf::Sprite());
    m_sprites.at(3).setTexture(ImageHandler::getTexture(SpriteList::PATH));
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
          sprite = m_sprites.at(0);
          break;
        case MapIdentifier::START:
          sprite = m_sprites.at(1);
          break;
        case MapIdentifier::END:
          sprite = m_sprites.at(2);
          break;
        case MapIdentifier::PATH:
          sprite = m_sprites.at(3);
          break;
        default:
          sprite = m_sprites.at(0);
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
