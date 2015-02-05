#include <towerdefense/Map.h>

namespace towerdefense {

  Map::Map(){}

  Map::Map(std::string levelpath, int width, int height){
    setWidth(width);
    setHeight(height);
    changeLevel(levelpath);
  }

  Map::~Map(){
  }

  void Map::update(float dt){
  }

  void Map::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture;

    for(unsigned int i=0; i<m_level.size(); ++i){
      std::vector<MapIdentifier> line = m_level[i];
      for(unsigned int j=0; j<line.size(); ++j){
        switch(line[j]){
        case MapIdentifier::FIELD:
          texture = ImageHandler::getTexture(SpriteList::FIELD);
          break;
        case MapIdentifier::START:
          texture = ImageHandler::getTexture(SpriteList::START);
          break;
        case MapIdentifier::END:
          texture = ImageHandler::getTexture(SpriteList::END);
          break;
        case MapIdentifier::CROSSINGPOINT:
        case MapIdentifier::PATH:
          texture = ImageHandler::getTexture(SpriteList::PATH);
          break;
        default:
          texture = ImageHandler::getTexture(SpriteList::FIELD);
          break;
        }
        sprite.setTexture(texture);
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
        window.draw(sprite);
      }
    }
  }

  std::vector<std::vector<MapIdentifier>> Map::getLevel(){
      return m_level;
  }

  void Map::setWidth(int width){
    if(width > 0) {
      m_width = width;
    }
  }

  void Map::setHeight(int height){
    if(height > 0) {
      m_height = height;
    }
  }

  void Map::setTileWidth(int nTile){
    m_tileWidth = m_width/nTile;
  }

  void Map::setTileHeight(int nTile){
    m_tileHeight = m_height/nTile;
  }

  void Map::changeLevel(std::string levelpath){
    std::ifstream levelTxt(levelpath);
    std::string line;
    m_level = std::vector<std::vector<MapIdentifier>>();

    // Loading text file for level definition
    if (levelTxt.is_open())
    {
      unsigned int i=0;
      int j=0;
      while(getline(levelTxt,line))
      {
        m_level.push_back(std::vector<MapIdentifier>());
        for(i=0; i<line.length(); i++){
          switch(line[i]){
          case '#':
            m_level.at(j).push_back(MapIdentifier::FIELD);
            break;
          case 'D':
            m_level.at(j).push_back(MapIdentifier::START);
            break;
          case 'A':
            m_level.at(j).push_back(MapIdentifier::END);
            m_crossingPoints.push_back(CrossingPoint(i, j));
            break;
          case 'C':
            m_level.at(j).push_back(MapIdentifier::CROSSINGPOINT);
            m_crossingPoints.push_back(CrossingPoint(i, j));
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
      setTileWidth(i);
      setTileHeight(j);
    }
    else {
      std::cout << "Unable to open level file";
    }
  }

  CrossingPoint* Map::getEnd(){
    return &m_crossingPoints.back();
  }
}
