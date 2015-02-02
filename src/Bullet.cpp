#include <towerdefense/Bullet.h>

namespace towerdefense {

  Bullet::Bullet(float posX,float posY, float posCX, float posCY){
    m_posX=posX;
    m_posY=posY;
  }

    void Bullet::update(float dt){

  }

    void Bullet::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::BULLET);

    sprite.setTexture(texture);
    sprite.setPosition(m_posX, m_posY);
    window.draw(sprite);
  }

}
