#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <vector>

#include <SFML/graphics.hpp>

namespace towerdefense{

  class ImageHandler {
  public:
    ImageHandler();
    ~ImageHandler();

    sf::Sprite getSprite();
  private:
    std::vector<sf::Sprite> m_sprites;
  };

}

#endif // IMAGEHANDLER_H
