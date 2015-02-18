#include <towerdefense/Bullet.h>

namespace towerdefense {

  Bullet::Bullet(float posX,float posY, Enemy* e){
    m_posX=posX;
    m_posY=posY;
    m_cible = e;
  }

  void Bullet::update(float dt){
    if (m_posX <= m_cible->GetPosX()-0.1 || m_posX >= m_cible->GetPosX()+0.1){
      if(m_cible->GetPosX() - m_posX < 0){
        m_posX -= dt*1.105;
      } else {
        m_posX += dt*1.105;
      }
    }

    if(m_posY <= m_cible->GetPosY()-0.1 || m_posY >= m_cible->GetPosY()+0.1){
      if(m_cible->GetPosY() - m_posY < 0){
        m_posY -= dt*1.105;
      } else {
        m_posY += dt*1.105;
      }
    }

    if (m_posX >= m_cible->GetPosX()-0.1
        && m_posX <= m_cible->GetPosX()+0.1
        && m_posY >= m_cible->GetPosY()-0.1
        && m_posY <= m_cible->GetPosY()+0.1){
// TODO (Erizino#1#): Need to add dmg to enemy

    }
  }

  void Bullet::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::BULLET);

    sprite.setTexture(texture);
    sprite.setPosition(m_posX, m_posY);
    window.draw(sprite);
  }

  float Bullet::getX(){
    return m_posX;
  }

  float Bullet::getY(){
    return m_posY;
  }

  Enemy* Bullet::getCible(){
    return m_cible;
  }
}
