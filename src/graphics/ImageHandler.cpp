#include <towerdefense/graphics/ImageHandler.h>

#include "../src/bin/config.h.in"

namespace towerdefense {

  ImageHandler::ImageHandler(){
  }

  ImageHandler::~ImageHandler(){
  }

  sf::Sprite ImageHandler::getSprite(){
    return m_sprites.at(0);
  }
}
