#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <iostream>
#include <vector>

#include <SFML/graphics.hpp>

namespace towerdefense{

  enum class SpriteList {
        PATH,
        FIELD,
        START,
        END,
        ENEMY,
        TOWER,
        TANK,
        BULLET,
  };

  class ImageHandler {
  public:
    static void initialize();
    static void freedisk();

    static sf::Texture getTexture(SpriteList selected);
  private:
    static std::vector<sf::Texture *> m_textures;

    ImageHandler();

    static sf::Texture* createPTexture();
  };

}

#endif // IMAGEHANDLER_H
