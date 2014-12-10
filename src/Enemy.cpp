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

  void Enemy::SetImage(const char* image){
    m_image=image;
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

  const char* Enemy::GetImage(){
    return m_image;
  }

  int Enemy::GetDefense(){
    return m_defense;
  }

  Enemy::Enemy(int speed,int life,int level,int coin,const char* image, int defense, int posX, int posY)
  {
    m_life = life;
    m_speed = speed;
    m_level = level;
    m_coin = coin;
    m_image = image;
    m_defense = defense*level;
    m_posX = posX;
    m_posY = posY;
  }

  void Enemy::GiveSprite(){
    sf::Texture enemy;
    sf::Sprite spriteEnemy;
    int m_tileWidth=500/10;
    int m_tileHeight=500/5;

    if(!enemy.loadFromFile(GetImage(), sf::IntRect(10,10,m_tileWidth,m_tileHeight)))
    {
        printf("Enemy's Texture can't be load ! Error !");
        exit(1);
    }

    spriteEnemy.setTexture(enemy);

    m_sprite= spriteEnemy;
  }

  sf::Sprite Enemy::Show(){
    return m_sprite;
  }

  void Enemy::update(float dt){
/*
    unsigned int x=en.getPosX();
    unsigned int y=en.getPosY();
    unsigned int xb=en.getPosXb();
    unsigned int yb=en.getPosYb();
    std::string& line= m_level[y+1];

    if((line[x]=='.')&&(yb!=y+1)){
      en.SetPosYb(en.getPosY());
      en.SetPosY(y+1);
    }else {
      line= m_level[y];
      if((line[x+1]=='.')&&(xb!=x+1)){
        en.SetPosXb(en.getPosX());
        en.SetPosX(x+1);
      }else{
        line= m_level[y];
        if((line[x-1]=='.')&&(xb!=x-1)){
          en.SetPosXb(en.getPosX());
          en.SetPosX(x-1);
        }else{
          line= m_level[y-1];
          if((line[x]=='.')&&(yb!=y-1)){
            en.SetPosYb(en.getPosY());
            en.SetPosY(y-1);
          }
        }
      }
    }
//*/
  }

  // DEMERDE TOI AVEC TES FONCTIONS UPDATE ET RENDER
  void Enemy::render(sf::RenderWindow& window){
/*
    if(((j)==to.getPosX())&& ((i==to.getPosY()))){// we put the tower on map
      sprite=to.Show();
      sprite.setPosition(to.getPosX()*m_tileWidth, to.getPosY()*m_tileHeight);
    }else{
      if(((j)==en.getPosX())&& ((i==en.getPosY()))){//we put the enemy on map
        sprite=en.Show();
        sprite.setPosition(en.getPosX()*m_tileWidth, en.getPosY()*m_tileHeight);
      }else{
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
      }
    }
//*/
  }

}
