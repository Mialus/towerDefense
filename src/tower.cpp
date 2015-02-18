#include <towerdefense/Tower.h>

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

  Tower::Tower(int level,int degat, float posX, float posY, EnemyManager* em){
    setLevel(level);
    setDegat(degat,level);
    setPosX(posX);
    setPosY(posY);
    m_emanager = em;
  }

// TODO (Erizino#1#): Fix Bullet creation
  void Tower::update(float dt){
    for(Enemy* e : m_emanager->getAllEnemies()){
      if((e->GetPosX()-m_posX < 100 && e->GetPosX()-m_posX > -100)
         && (e->GetPosY()-m_posY < 100 && e->GetPosY()-m_posY > -100)){
          std::cout << "Bullet Created!" << std::endl;
        m_bullets.push_back(new Bullet(m_posX+ImageHandler::getTexture(SpriteList::TOWER).getSize().x/2, m_posY, e));
      }
    }
    for(Bullet* b : m_bullets){
        std::cout << "Bullet Update!" << std::endl;
      if (b->getX() >= b->getCible()->GetPosX()-0.1
        && b->getX() <= b->getCible()->GetPosX()+0.1
        && b->getY() >= b->getCible()->GetPosY()-0.1
        && b->getY() <= b->getCible()->GetPosY()+0.1){
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
    std::cout << "Bullet Rendered1!" << std::endl;
    window.draw(sprite);
    std::cout << "Bullet Rendered2!" << std::endl;
// TODO (Erizino#1#): Fiw bullet render
    for(Bullet* b : m_bullets){
        std::cout << "Bullet Rendered3!" << std::endl;
      b->render(window);
    }
  }
}
