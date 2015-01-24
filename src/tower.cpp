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

  Tower::Tower(int level,int degat, int posX, int posY){
    setLevel(level);
    setDegat(degat,level);
    setPosX(posX);
    setPosY(posY);
  }

  /*void Tower::giveSprite(){
    sf::Texture tower;
    sf::Sprite spriteTower;
    int m_tileWidth=500/10;
    int m_tileHeight=500/5;

    if(!tower.loadFromFile(getImage(), sf::IntRect(10,10,m_tileWidth,m_tileHeight)))
    {
      printf("Enemy's Texture don't be load ! Error !");
      exit(1);
    }

    spriteTower.setTexture(tower);

    m_sprite= spriteTower;
  }*/


  void Tower::update(float dt){
  }
}
