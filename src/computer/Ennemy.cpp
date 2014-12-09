#include <towerdefense/computer/Ennemy.h>

namespace towerdefense {

void Ennemy::SetCoin(int coin)
{
    m_coin=coin;
}

void Ennemy::SetLevel(int level)
{
    m_level=level;
}

    void Ennemy::SetPosX(int posX){
        m_posX=posX;
    }
    void Ennemy::SetPosY(int posY){
        m_posY=posY;
    }

    void Ennemy::SetPosXb(int posXb){
        m_posXb=posXb;
    }
    void Ennemy::SetPosYb(int posYb){
        m_posYb=posYb;
    }

    int Ennemy::getPosX(){
        return m_posX;
    }
    int Ennemy::getPosY(){
        return m_posY;
    }

    int Ennemy::getPosXb(){
        return m_posXb;
    }
    int Ennemy::getPosYb(){
        return m_posYb;
    }



void Ennemy::SetDefense(int def, int lvl){
    m_defense=def*lvl;
}

void Ennemy::SetLife(int life)
{
    m_life=life;
}

void Ennemy::SetSpeed(int speed)
{
    m_speed=speed;
}

void Ennemy::SetImage(const char* image)
{
    m_image=image;
}

int Ennemy::GetCoin()
{
    return m_coin;
}

int Ennemy::GetLevel()
{
    return m_level;
}

int Ennemy::GetLife()
{
    return m_life;
}

int Ennemy::GetSpeed()
{
    return m_speed;
}

const char* Ennemy::GetImage()
{
    return m_image;
}

int Ennemy::getDefense(){
    return m_defense;
}

Ennemy::Ennemy(int speed,int life,int level,int coin,const char* image, int defense, int posX, int posY)
{
    Ennemy::SetLife(life);
    Ennemy::SetSpeed(speed);
    Ennemy::SetLevel(level);
    Ennemy::SetCoin(coin);
    Ennemy::SetImage(image);
    Ennemy::SetDefense(defense,level);
    Ennemy::SetPosX(posX);
    Ennemy::SetPosY(posY);

}
void Ennemy::giveSprite(){

    sf::Texture ennemy;
    sf::Sprite spriteEnnemy;
    int m_tileWidth=500/10;
    int m_tileHeight=500/5;

    if(!ennemy.loadFromFile(GetImage(), sf::IntRect(10,10,m_tileWidth,m_tileHeight)))
    {
        printf("Enemy's Texture don't be load ! Error !");
        exit(1);
    }

    spriteEnnemy.setTexture(ennemy);

    m_sprite= spriteEnnemy;

}

sf::Sprite Ennemy::Show(){
  return m_sprite;
}

}
