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
   //std::cout << "position Ennemy: " << m_posX << "," << m_posY << std::endl;
    sprite.setPosition(m_posX*50, m_posY*100);
    window.draw(sprite);
  }

  void Enemy::update(float dt, Map* iMap){
    std::vector<std::vector<MapIdentifier>> level = iMap->getLevel();
    for(int i=-1; i<2; i++){ // boucle initialize for enemy position Y
      if(i+(int)m_posY>=0){ // excluding outbounds
        std::vector<MapIdentifier> line = level[(int)(i+m_posY)]; // Getting line
        for(int j=-1; j<2; j++){ // boucle initialize for enemy position X
          if(j+(int)m_posX>=0){ // Excluding outbounds
            // std::cout << "position Ennemy: " << (int)(i+m_posX) << "," << (int)(j+m_posY) << std::endl;
            if(line[j+(int)m_posX]==MapIdentifier::PATH){ // Si c'est un chemin
              if((j+(int)m_posX!=m_posXb)||(i+(int)m_posY!=m_posYb)){ // si ce n'est pas la case précédente
                if((j+(int)m_posX!=j+m_posX)||(i+(int)m_posY!=i+m_posY)){ // si ce n'est pas la case actuel
                  m_posXb=m_posX;
                  m_posYb=m_posY;
                  // std::cout << "position Ennemy: " << m_posX << "," << m_posY << std::endl;
                  m_posX=m_posX+(j*dt);
                  m_posY=m_posY+(i*dt);
                  // std::cout << "position Ennemy: " << m_posX << "," << m_posY << std::endl;
                }
              }
            }
          }
        }
      }
    }
  }

  void Enemy::resetIds(){
    m_current_id = 0;
  }
}
