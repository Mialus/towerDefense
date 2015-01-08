#include <towerdefense/ImageHandler.h>

namespace towerdefense {

  std::vector<sf::Texture> ImageHandler::m_textures = std::vector<sf::Texture>();

  ImageHandler::ImageHandler(){
    initialize();
  }

  void ImageHandler::initialize(){
    // Loading Map's texture
    m_textures.push_back(sf::Texture());
    if(!m_textures.at(0).loadFromFile("res/img/start.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Start texture of the map can't be loaded !");
      exit(1);
    }

    m_textures.push_back(sf::Texture());
    if(!m_textures.at(1).loadFromFile("res/img/path.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Path texture of the map can't be loaded !");
      exit(1);
    }

    m_textures.push_back(sf::Texture());
    if(!m_textures.at(2).loadFromFile("res/img/field.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Field texture of the map can't be loaded !");
      exit(1);
    }
    // END LOAD MAP TEXTURE

    // LOADING OTHERS ENTITY TEXTURE
    m_textures.push_back(sf::Texture());
    if(!m_textures.at(3).loadFromFile("res/img/enemy.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Enemy texture can't be loaded !");
      exit(1);
    }

    m_textures.push_back(sf::Texture());
    if(!m_textures.at(4).loadFromFile("res/img/tower.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Tower texture can't be loaded !");
      exit(1);
    }

    m_textures.push_back(sf::Texture());
    if(!m_textures.at(5).loadFromFile("res/img/end.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("End texture can't be loaded !");
      exit(1);
    }
    // END LOAD OTHERS ENTITY TEXTURE
  }

  sf::Texture ImageHandler::getTexture(SpriteList selected){
    switch(selected){
    case SpriteList::START:
      return m_textures.at(0);
      break;
    case SpriteList::PATH:
      return m_textures.at(1);
      break;
    case SpriteList::FIELD:
      return m_textures.at(2);
      break;
    case SpriteList::ENEMY:
      return m_textures.at(3);
      break;
    case SpriteList::TOWER:
      return m_textures.at(4);
      break;
    case SpriteList::END:
      return m_textures.at(5);
      break;
    default:
      return m_textures.at(2);
      break;
    }
  }

}
