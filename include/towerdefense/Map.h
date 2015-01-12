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
    Map(std::string levelpath);
    ~Map();

    void update(float dt);
    void render(sf::RenderWindow& window);

    void setWidth(int width);
    void setHeight(int height);

  private:
    unsigned int m_tileWidth;
    unsigned int m_tileHeight;
    unsigned int m_width;
    unsigned int m_height;
    std::vector<std::vector<MapIdentifier>> m_level;
  };

}

#endif // MAP_H
