#include <towerdefense/computer/Ennemy.h>

void Ennemy::SetCoin(int coin)
{
    m_coin=coin;
}

void Ennemy::SetLevel(int level)
{
    m_level=level;
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

Ennemy::Ennemy()
{
    Ennemy::SetLife(50);
    Ennemy::SetSpeed(1);
    Ennemy::SetLevel(1);
    Ennemy::SetCoin(20);
    Ennemy::SetImage("../../res/computer/enemy.jpg");
}

/*Ennemy::Ennemy(int speed,int life,int level,int coin,const char* image)
{
    Ennemy::SetLife(life);
    Ennemy::SetSpeed(speed);
    Ennemy::SetLevel(level);
    Ennemy::SetCoin(coin);
    Ennemy::SetImage(image);
}*/

sf::Sprite Ennemy::Show()
{
    sf::Texture ennemy;
    sf::Sprite spriteEnnemy;

    if(!ennemy.loadFromFile(GetImage(), sf::IntRect(10,10,10,10)))// commence en 10,10 et fais 10 par 10
    {
        printf("Enemy's Texture don't be load ! Error !");
        exit(1);
    }

    spriteEnnemy.setTexture(ennemy);

    return spriteEnnemy;
}


//Main de test
int main() {
  // initialize
  Ennemy enn = Ennemy();
  towerdefense::World world;
  sf::RenderWindow window(sf::VideoMode(500, 500), "Tower Defense (version " GAME_VERSION ")");

  while (window.isOpen())
  {
//     window.draw(Ennemy::Show());
  }

}
