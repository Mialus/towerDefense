#include <towerdefense/Tower.h>
#include <SFML/Graphics.hpp>

namespace towerdefense {

  void Tower::setLevel(int level){
    m_level=level;
  }

  void Tower::setDegat(int degat,int level){
    m_degat=degat*level;
  }

  void Tower::setPosX(int posX){
    m_posX=posX;
  }

  void Tower::setPosY(int posY){
    m_posY=posY;
  }

  int Tower::getLevel(){
    return m_level;
  }

  int Tower::getDegat(){
    return m_degat;
  }

  int Tower::getPosX(){
    return m_posX;
  }

  int Tower::getPosY(){
    return m_posY;
  }

  Tower::Tower(int level,int degat, float posX, float posY){
    setLevel(level);
    setDegat(degat,level);
    setPosX(posX);
    setPosY(posY);
  }

  void Tower::update(float dt){

  }

  void Tower::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::TOWER);

    sprite.setTexture(texture);
    sprite.setPosition(m_posX, m_posY);
    window.draw(sprite);
  }
}
