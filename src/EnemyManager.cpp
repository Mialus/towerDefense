#include "towerdefense/EnemyManager.h"


namespace towerdefense {

EnemyManager::EnemyManager(int nombreEnemy,unsigned int tileW, unsigned int tileH, std::vector<std::vector<MapIdentifier>> level)
{
    m_level=level;
    m_tileWidth=tileW;
    m_tileHeight=tileH;
    m_nbrEnnemy=nombreEnemy;
    while(nombreEnemy>0){
        allEnemy.push_back(Tank());
        nombreEnemy--;
    }

}
 void EnemyManager::updateE(float dt){
    int nombreEnemy=m_nbrEnnemy;

    while(nombreEnemy>0){
        allEnemy.at(nombreEnemy).update(dt, m_level);
        nombreEnemy--;
    }
}

  void EnemyManager::render(sf::RenderWindow& window){
    int nombreEnemy=m_nbrEnnemy;
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::ENEMY);

    sprite.setTexture(texture);
         while(nombreEnemy>0){
                Enemy en=allEnemy.at(nombreEnemy);
                sprite.setPosition(en.GetPosY()*m_tileWidth,
                                    en.GetPosX()*m_tileHeight);
                window.draw(sprite);
            }
            nombreEnemy--;
}




EnemyManager::~EnemyManager(){}

}
