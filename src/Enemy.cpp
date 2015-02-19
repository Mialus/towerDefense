#include <towerdefense/Enemy.h>

namespace towerdefense {

  float Enemy::GetPosX(){
    return m_posX;
  }

  float Enemy::GetPosY(){
    return m_posY;
  }

  int Enemy::GetCoin(){
    return m_coin;
  }

  int Enemy::GetLife(){
    return m_life;
  }

  float Enemy::GetSpeed(){
    return m_speed;
  }

  int Enemy::GetDefense(){
    return m_defense;
  }

  void Enemy::loseLife(int life){
    std::cout << "Avant : " << m_life;
    m_life -= life;
    std::cout << "  Après : " << m_life << std::endl;
  }

  Enemy::Enemy(int speed,int life,int coin, int defense, float posY, float posX)
  {
    m_life = life;
    m_speed = speed;
    m_posX = posX+0.001;
    m_posY = posY;
    m_posXb = -5;
    m_posYb = -5;
    m_coin = coin;
    m_defense = defense;
    m_currentCp = '0';
  }

  Enemy::~Enemy() {
  }

  void Enemy::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::ENEMY);

    sprite.setTexture(texture);
    sprite.setPosition(m_posX*50, m_posY*100);
    window.draw(sprite);
  }

  void Enemy::update(float dt){
    for(CrossingPoint* cp : m_crossingPoints){
      if(cp->getId() == m_currentCp || m_crossingPoints.size() < 2){
        if (m_posX <= cp->getX()-0.1 || m_posX >= cp->getX()+0.1){
          if(cp->getX() - m_posX < 0){
            m_posX -= dt*0.905;
          } else {
            m_posX += dt*0.905;
          }
        }

        if(m_posY <= cp->getY()-0.1 || m_posY >= cp->getY()+0.1){
          if(cp->getY() - m_posY < 0){
            m_posY -= dt*0.905;
          } else {
            m_posY += dt*0.905;
          }
        }

        if (m_posX >= cp->getX()-0.1 && m_posX <= cp->getX()+0.1 && m_posY >= cp->getY()-0.1 && m_posY <= cp->getY()+0.1){
          m_crossingPoints.erase(remove(m_crossingPoints.begin(), m_crossingPoints.end(), cp), m_crossingPoints.end());
          m_currentCp++;
        }
      }
    }
  }

  void Enemy::setCrossingPoints(std::vector<CrossingPoint*> crossingPoints){
    m_crossingPoints = crossingPoints;
  }

  bool Enemy::endCorssingPoints(){
    return m_crossingPoints.empty();
  }
}
