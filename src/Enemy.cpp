#include <towerdefense/Enemy.h>

namespace towerdefense {

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

  Enemy::Enemy(int speed,int life,int level,int coin, int defense)
  {
    m_life = life;
    m_speed = speed;
    m_level = level;
    m_coin = coin;
    m_defense = defense*level;
  }

    Enemy::~Enemy() {
  }

    void Enemy::update(float dt, std::vector<std::vector<MapIdentifier>> level){
      if(dt){
            for(int i=-1; i<1; ++i){
            std::vector<MapIdentifier> line = level[i+m_posX];
            for(int j=-1; j<1; ++j){
                if(line[j+m_posY]==MapIdentifier::PATH){ // Si c'est un chemin
                    if((j+m_posY!=m_posYb)||(i+m_posX!=m_posXb)){ // si ce n'est pas la derniére case
                        if((j+m_posY!=m_posY)||(i+m_posX!=m_posX)){ // si ce n'est pas la case actuel
                            m_posXb=m_posX;
                            m_posYb=m_posY;

                            m_posX+=i;
                            m_posY+=j;
                        }

                    }
                }



            }
            }
      }

  }
}
