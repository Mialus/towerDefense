#include "towerdefense/EnemyManager.h"


namespace towerdefense {

EnemyManager::EnemyManager(int nombreEnemy,unsigned int tileW, unsigned int tileH, std::vector<std::vector<MapIdentifier>> level)
{
    m_level=level;
    m_tileWidth=tileW;
    m_tileHeight=tileH;
    m_nbrEnnemy=nombreEnemy;
    for(int it = 0; it<nombreEnemy;it++){
        allEnemy.push_back(Tank());
            for(unsigned int i=0; i<level.size(); ++i){
            std::vector<MapIdentifier> line = level[i];
            for(unsigned int j=0; j<level.size(); ++j){
                if(line[j]==MapIdentifier::START){
                            allEnemy.at(it).SetPosX(i);
                            allEnemy.at(it).SetPosY(j);
                }
            }
            }
    }
}
 void EnemyManager::update(float dt){
    int nombreEnemy=m_nbrEnnemy;

    while(nombreEnemy>0){
        allEnemy.at(nombreEnemy-1).update(dt, m_level);
        nombreEnemy--;
    }
}

  void EnemyManager::render(sf::RenderWindow& window){
/*    int nombreEnemy=m_nbrEnnemy;
    sf::Sprite sprite;
    sf::Texture texture = ImageHandler::getTexture(SpriteList::ENEMY);

    sprite.setTexture(texture);
         while(nombreEnemy>0){
                Enemy en=allEnemy.at(nombreEnemy);
                sprite.setPosition(en.GetPosY()*m_tileWidth,
                                    en.GetPosX()*m_tileHeight);
                window.draw(sprite);
            }
            nombreEnemy--;*/
        for(int i=0;i<m_nbrEnnemy;i++){
            allEnemy.at(i).render(window);
        }
}




EnemyManager::~EnemyManager(){}

}
