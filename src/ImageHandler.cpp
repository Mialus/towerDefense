#include <towerdefense/ImageHandler.h>

namespace towerdefense {

  std::vector<sf::Texture*> ImageHandler::m_textures = std::vector<sf::Texture*>();

  ImageHandler::ImageHandler(){
    initialize();
  }

  void ImageHandler::initialize(){
    sf::Texture* texture;

    // Loading Map's texture
    if(!texture->loadFromFile("res/img/start.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Start texture of the map can't be loaded !");
      exit(1);
    } else {
      m_textures.push_back(texture);
    }

    if(!texture->loadFromFile("res/img/path.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Path texture of the map can't be loaded !");
      exit(1);
    } else {
      m_textures.push_back(texture);
    }

    if(!texture->loadFromFile("res/img/field.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Field texture of the map can't be loaded !");
      exit(1);
    } else {
      m_textures.push_back(texture);
    }
    // END LOAD MAP TEXTURE

    // LOADING OTHERS ENTITY TEXTURE
    if(!texture->loadFromFile("res/img/enemy.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Enemy texture can't be loaded !");
      exit(1);
    } else {
      m_textures.push_back(texture);
    }

    if(!texture->loadFromFile("res/img/tower.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("Tower texture can't be loaded !");
      exit(1);
    } else {
      m_textures.push_back(texture);
    }

    if(!texture->loadFromFile("res/img/end.jpg",
                                    sf::IntRect(0,0,32,32))){
      printf("End texture can't be loaded !");
      exit(1);
    } else {
      m_textures.push_back(texture);
    }
    // END LOAD OTHERS ENTITY TEXTURE
  }

  sf::Sprite ImageHandler::getSprite(SpriteList selected){
    sf::Sprite sprite;
    switch(selected){
    case SpriteList::START:
      sprite.setTexture(*m_textures.at(0));
      break;
    case SpriteList::PATH:
      sprite.setTexture(*m_textures.at(1));
      break;
    case SpriteList::FIELD:
      sprite.setTexture(*m_textures.at(2));
      break;
    case SpriteList::ENEMY:
      sprite.setTexture(*m_textures.at(3));
      break;
    case SpriteList::TOWER:
      sprite.setTexture(*m_textures.at(4));
      break;
    case SpriteList::END:
      sprite.setTexture(*m_textures.at(5));
      break;
    default:
      sprite.setTexture(*m_textures.at(2));
      break;
    }
    return sprite;
  }

}
