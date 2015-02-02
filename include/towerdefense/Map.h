#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include <towerdefense/Entity.h>
#include <towerdefense/ImageHandler.h>

namespace towerdefense{

  enum class MapIdentifier {
        PATH,
        FIELD,
        START,
        END,
  };

  class Map : public Entity {
  public:
    Map();
    Map(std::string levelpath, int width, int height);
    ~Map();

    void update(float dt);
    void render(sf::RenderWindow& window);

    std::vector<std::vector<MapIdentifier>> getLevel();

    void setWidth(int width);
    void setHeight(int height);
    void setTileWidth(int nTile);
    void setTileHeight(int nTile);
    void changeLevel(std::string levelpath);
    int GetEndX();
    int GetEndY();

  private:
    unsigned int m_tileWidth;
    unsigned int m_tileHeight;
    unsigned int m_width;
    unsigned int m_height;
    std::vector<std::vector<MapIdentifier>> m_level;
    int m_endX, m_endY;
  };

}

#endif // MAP_H
