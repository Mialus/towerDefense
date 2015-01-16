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
    // Start
    m_textures.push_back(createPTexture());
    if(!m_textures.at(0)->loadFromFile("res/img/spawn.png")){
      std::cout << "Start texture of the map can't be loaded !" << std::endl;
      exit(1);
    }

    // Path
    m_textures.push_back(createPTexture());
    if(!m_textures.at(1)->loadFromFile("res/img/Sand.png")){
      std::cout << "Path texture of the map can't be loaded !" << std::endl;
      exit(1);
    }

    // Field
    m_textures.push_back(createPTexture());
    if(!m_textures.at(2)->loadFromFile("res/img/Grass.png")){
      std::cout << "Field texture of the map can't be loaded !" << std::endl;
      exit(1);
    }
    // END LOAD MAP TEXTURE

    // LOADING OTHERS ENTITY TEXTURE
    // Enemy
    m_textures.push_back(createPTexture());
    if(!m_textures.at(3)->loadFromFile("res/img/enemy.png")){
      std::cout << "Enemy texture can't be loaded !" << std::endl;
      exit(1);
    }

    // Tower
    m_textures.push_back(createPTexture());
    if(!m_textures.at(4)->loadFromFile("res/img/tower.png")){
      std::cout << "Tower texture can't be loaded !" << std::endl;
      exit(1);
    }

    // End
    m_textures.push_back(createPTexture());
    if(!m_textures.at(5)->loadFromFile("res/img/door.png")){
      std::cout << "End texture can't be loaded !" << std::endl;
      exit(1);
    }

    // Tank
    m_textures.push_back(createPTexture());
    if(!m_textures.at(6)->loadFromFile("res/img/tank.png")){
      std::cout << "End texture can't be loaded !" << std::endl;
      exit(1);
    }

    // Bullet
    m_textures.push_back(createPTexture());
    if(!m_textures.at(7)->loadFromFile("res/img/bullet.png")){
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
    case SpriteList::TANK:
      return *(m_textures.at(6));
      break;
    case SpriteList::BULLET:
      return *(m_textures.at(7));
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
