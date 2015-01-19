#include <towerdefense/Tower.h>
#include <SFML/Graphics.hpp>

namespace towerdefense {

  void tower::setLevel(int level){
    m_level=level;
  }

  void tower::setDegat(int degat,int level){
    m_degat=degat*level;
  }

  void tower::setPosX(int posX){
    m_posX=posX;
  }

  void tower::setPosY(int posY){
    m_posY=posY;
  }

  int tower::getLevel(){
    return m_level;
  }

  int tower::getDegat(){
    return m_degat;
  }

  int tower::getPosX(){
    return m_posX;
  }

  int tower::getPosY(){
    return m_posY;
  }

  tower::tower(int level,int degat, int posX, int posY){
    setLevel(level);
    setDegat(degat,level);
    setPosX(posX);
    setPosY(posY);
  }

  /*void tower::giveSprite(){
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


  void tower::update(float dt){
  }
}
