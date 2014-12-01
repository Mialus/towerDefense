#include <towerdefense/graphics/Map.h>
#include <boost/filesystem.hpp>
#include <towerdefense/Resource.h>
#include <towerdefense/World.h>
#include <SFML/Graphics.hpp>
#include "../src/bin/config.h.in"

namespace towerdefense {

  Map::Map(){
    std::ifstream levelTxt("res/maps/level1.txt");
    std::string line;

    m_tileWidth=10;
    m_tileHeight=10;
    m_width=500;
    m_height=500;

    // Loading text file for level definition
    if (levelTxt.is_open())
    {
      while(getline(levelTxt,line))
      {
        m_level.push_back(line);
      }
      levelTxt.close();
    }
    else {
      std::cout << "Unable to open file";
    }

    // Loading Map's texture
    if(!m_textureEnemy.loadFromFile("res/maps/enemy.jpg",
                                    sf::IntRect(0,0,m_tileWidth,m_tileHeight))){
      printf("A texture of the map can't be loaded !");
      exit(1);
    } else {
      m_spriteEnemy.setTexture(m_textureEnemy);
    }

    if(!m_textureTower.loadFromFile("res/maps/tower.jpg",
                                    sf::IntRect(0,0,m_tileWidth,m_tileHeight))){
      printf("A texture of the map can't be loaded !");
      exit(1);
    } else {
      m_spriteTower.setTexture(m_textureTower);
    }
    // END LOAD TEXTURE
  }

  Map::~Map(){
  }

  void Map::update(){
  }

  void Map::render(sf::RenderWindow& window){
    sf::Sprite sprite;

    for(unsigned int i=0; i<m_level.size(); ++i){
      std::string& line = m_level[i];
      for(unsigned int j=0; j<line.size(); ++i){
        switch(line[j]){
        case '#':
          sprite = m_spriteTower;
          break;
        case 'D':
        case 'A':
        case '.':
          sprite = m_spriteEnemy;
          break;
        default:
          sprite = m_spriteEnemy;
          break;
        }
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
        window.draw(sprite);
      }
    }
  }

  sf::Texture Map::GetTextureEnemy(){ return m_textureEnemy; }
  sf::Sprite Map::GetSpriteEnemy(){ return m_spriteEnemy; }
  sf::Texture Map::GetTextureTower(){ return m_textureTower; }
  sf::Sprite Map::GetSpriteTower(){ return m_spriteTower; }

}

//*
int main() {
  // initialize
  towerdefense::World world;
  sf::RenderWindow window(sf::VideoMode(500, 500), "Tower Defense (version " GAME_VERSION ")");
  towerdefense::Map *mapLevel;

  while (window.isOpen())
  {
     mapLevel->render(window);
  }

}
//*/
