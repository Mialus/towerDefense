#include <towerdefense/Enemy.h>

namespace towerdefense {

  int Enemy::m_current_id = 0;

  void Enemy::SetCoin(int coin){
    m_coin=coin;
  }

  void Enemy::SetLevel(int level){
    m_level=level;
  }

  void Enemy::SetPosX(int posX){
    m_posX=posX;
  }

  void Enemy::SetPosY(int posY){
    m_posY=posY;
  }

  void Enemy::SetPosXb(int posXb){
    m_posXb=posXb;
  }

  void Enemy::SetPosYb(int posYb){
    m_posYb=posYb;
  }

  int Enemy::GetPosX(){
    return m_posX;
  }

  int Enemy::GetPosY(){
    return m_posY;
  }

  int Enemy::GetPosXb(){
    return m_posXb;
  }

  int Enemy::GetPosYb(){
    return m_posYb;
  }

  void Enemy::SetDefense(int def, int lvl){
    m_defense=def*lvl;
  }

  void Enemy::SetLife(int life){
    m_life=life;
  }

  void Enemy::SetSpeed(int speed){
    m_speed=speed;
  }

  int Enemy::GetCoin(){
    return m_coin;
  }

  int Enemy::GetLevel(){
    return m_level;
  }

  int Enemy::GetLife(){
    return m_life;
  }

  int Enemy::GetSpeed(){
    return m_speed;
  }

  int Enemy::GetDefense(){
    return m_defense;
  }

  int Enemy::GetId(){
    return m_id;
  }

  Enemy::Enemy(int speed,int life,int level,int coin, int defense, float posY, float posX)
  {
    m_id = m_current_id;
    m_life = life;
    m_speed = speed;
    m_level = level;
    m_posX = posX+0.001;
    m_posY = posY;
    m_posXb = -5;
    m_posYb = -5;
    m_coin = coin;
    m_defense = defense*level;
    m_current_id++;
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
    if(!m_crossingPoints.empty()){
      CrossingPoint* cp = m_crossingPoints.at(0);

      if (!(m_posX >= cp->getX()-10 || m_posX <= cp->getX()+10)){
        m_posX = m_posX+(m_posX - cp->getX())*dt*0.5;
      }

      if(!(m_posY >= cp->getY()+10 || m_posY <= cp->getY()-10)){
        m_posY = m_posY+(m_posY - cp->getY())*dt*0.5;
      }

      if ((m_posX >= cp->getX()-10 && m_posX <= cp->getX()+10)
          && (m_posY >= cp->getY()+10 && m_posY <= cp->getY()-10)){
              m_crossingPoints.erase(m_crossingPoints.begin());
              cp = m_crossingPoints.at(0);
      }
    }
  }

  void Enemy::resetIds(){
    m_current_id = 0;
  }

  void Enemy::setCrossingPoints(std::vector<CrossingPoint*> crossingPoints){
    m_crossingPoints = crossingPoints;
  }

  bool Enemy::endCorssingPoints(){
    return m_crossingPoints.empty();
  }
}
