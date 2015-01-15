#include <towerdefense/ImageHandler.h>

namespace towerdefense {

  std::vector<sf::Texture *> ImageHandler::m_textures = std::vector<sf::Texture *>();

  ImageHandler::ImageHandler(){
  }

  sf::Texture* ImageHandler::createPTexture(){
    sf::Texture * texture = new sf::Texture();
    return texture;
  }

  void ImageHandler::initialize(){
    // Loading Map's texture
    m_textures.push_back(createPTexture());
    if(!m_textures.at(0)->loadFromFile("res/img/spawn.png")){
      std::cout << "Start texture of the map can't be loaded !" << std::endl;
      exit(1);
    }

    m_textures.push_back(createPTexture());
    if(!m_textures.at(1)->loadFromFile("res/img/Sand.png")){
      std::cout << "Path texture of the map can't be loaded !" << std::endl;
      exit(1);
    }

    m_textures.push_back(createPTexture());
    if(!m_textures.at(2)->loadFromFile("res/img/Grass.png")){
      std::cout << "Field texture of the map can't be loaded !" << std::endl;
      exit(1);
    }
    // END LOAD MAP TEXTURE

    // LOADING OTHERS ENTITY TEXTURE
    m_textures.push_back(createPTexture());
    if(!m_textures.at(3)->loadFromFile("res/img/enemy.jpg")){
      std::cout << "Enemy texture can't be loaded !" << std::endl;
      exit(1);
    }

    m_textures.push_back(createPTexture());
    if(!m_textures.at(4)->loadFromFile("res/img/tower.jpg")){
      std::cout << "Tower texture can't be loaded !" << std::endl;
      exit(1);
    }

    m_textures.push_back(createPTexture());
    if(!m_textures.at(5)->loadFromFile("res/img/door.png")){
      std::cout << "End texture can't be loaded !" << std::endl;
      exit(1);
    }
    // END LOAD OTHERS ENTITY TEXTURE
  }

  sf::Texture ImageHandler::getTexture(SpriteList selected){
    switch(selected){
    case SpriteList::START:
      return *(m_textures.at(0));
      break;
    case SpriteList::PATH:
      return *(m_textures.at(1));
      break;
    case SpriteList::FIELD:
      return *(m_textures.at(2));
      break;
    case SpriteList::ENEMY:
      return *(m_textures.at(3));
      break;
    case SpriteList::TOWER:
      return *(m_textures.at(4));
      break;
    case SpriteList::END:
      return *(m_textures.at(5));
      break;
    default:
      return *(m_textures.at(2));
      break;
    }
  }

  void ImageHandler::freedisk(){
    for(unsigned int i=0;i<m_textures.size();i++){
      delete m_textures.at(i);
    }
  }
}
