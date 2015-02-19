#include <towerdefense/Tower.h>

namespace towerdefense {

  int Tower::getDegat(){
    return m_degat;
  }

  int Tower::getPosX(){
    return m_posX;
  }

  int Tower::getPosY(){
    return m_posY;
  }

  Tower::Tower(int level,int degat, float posX, float posY, EnemyManager* em){
    m_level=level;
    m_degat=degat*level;
    m_posX=posX;
    m_posY=posY;
    m_emanager = em;
    m_dt_cumulated = 0;
  }

  void Tower::update(float dt){
    m_dt_cumulated += dt;
    for(Enemy* e : m_emanager->getAllEnemies()){
      if((e->GetPosX()-m_posX/50.0 <= 2.1 && e->GetPosX()-m_posX/50.0 >= -2.1)
         && (e->GetPosY()-m_posY/100.0 <= 2.1 && e->GetPosY()-m_posY/100.0 >= -2.1)
         && m_dt_cumulated > 1){
        m_bullets.push_back(new Bullet(m_posX+ImageHandler::getTexture(SpriteList::TOWER).getSize().x/2, m_posY, m_degat, e));
        m_dt_cumulated = 0;
      }
    }
    for(Bullet* b : m_bullets){
      if (b->getX()/50.0 >= b->getCible()->GetPosX()-0.1
        && b->getX()/50.0 <= b->getCible()->GetPosX()+0.1
        && b->getY()/100.0 >= b->getCible()->GetPosY()-0.1
        && b->getY()/100.0 <= b->getCible()->GetPosY()+0.1){
          m_bullets.erase(remove(m_bullets.begin(), m_bullets.end(), b), m_bullets.end());
      }
      b->update(dt);
    }
  }

  void Tower::render(sf::RenderWindow& window){
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::TOWER);

    sprite.setTexture(texture);
    sprite.setPosition(m_posX, m_posY);
    window.draw(sprite);
    for(Bullet* b : m_bullets){
      b->render(window);
    }
  }
}
