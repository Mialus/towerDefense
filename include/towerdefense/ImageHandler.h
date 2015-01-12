#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

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
  };

  class ImageHandler {
  public:

    ImageHandler();

    static void initialize();

    static sf::Texture getTexture(SpriteList selected);
  private:
    static std::vector<sf::Texture *> m_textures;

    static sf::Texture* createPTexture();
  };

}

#endif // IMAGEHANDLER_H
