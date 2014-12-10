#include <towerdefense/ImageHandler.h>

namespace towerdefense {

  ImageHandler::ImageHandler(){
  }

  ImageHandler::~ImageHandler(){
  }

  sf::Sprite ImageHandler::getSprite(){
    return m_sprites.at(0);
  }

}
