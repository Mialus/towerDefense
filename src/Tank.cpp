#include <towerdefense/Tank.h>

namespace towerdefense {

  Tank::~Tank(){}

  void Tank::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::TANK);

    sprite.setTexture(texture);
   //std::cout << "position Ennemy: " << m_posX << "," << m_posY << std::endl;
    sprite.setPosition(m_posX*50, m_posY*100);
    window.draw(sprite);
  }

}
