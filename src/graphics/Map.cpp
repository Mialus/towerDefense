#include <towerdefense/graphics/Map.h>
//*
#include <boost/filesystem.hpp>
#include <towerdefense/Resource.h>
#include <towerdefense/World.h>
#include "../src/bin/config.h.in"
//*/

namespace towerdefense {

  Map::Map(){
    std::ifstream levelTxt("res/maps/level2.txt");
    std::string line;
    sf::Texture texture;
    sf::Sprite sprite;

    m_tileWidth=500/10;
    m_tileHeight=500/5;
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
      std::cout << "Unable to open level file";
    }

    // Loading Map's texture
    if(!texture.loadFromFile("res/maps/path.jpg",
                                    sf::IntRect(0,0,m_tileWidth,m_tileHeight))){
      std::cout << "A texture of map can't be loaded !" << std::endl;
      exit(1);
    } else {
      sprite.setTexture(texture);
      m_sprites.push_back(sprite);
    }

    if(!texture.loadFromFile("res/maps/field.jpg",
                                    sf::IntRect(0,0,m_tileWidth,m_tileHeight))){
      std::cout << "A texture of map can't be loaded !" << std::endl;
      exit(1);
    } else {
      sprite.setTexture(texture);
      m_sprites.push_back(sprite);
    }

    if(!texture.loadFromFile("res/maps/start.jpg",
                                    sf::IntRect(0,0,m_tileWidth,m_tileHeight))){
      std::cout << "A texture of map can't be loaded !" << std::endl;
      exit(1);
    } else {
      sprite.setTexture(texture);
      m_sprites.push_back(sprite);
    }

    if(!texture.loadFromFile("res/maps/end.jpg",
                                    sf::IntRect(0,0,m_tileWidth,m_tileHeight))){
      std::cout << "A texture of map can't be loaded !" << std::endl;
      exit(1);
    } else {
      sprite.setTexture(texture);
      m_sprites.push_back(sprite);
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
      for(unsigned int j=0; j<line.size(); ++j){
        switch(line[j]){
        case '#':
          sprite = m_sprites.at(FIELD);
          break;
        case 'D':
          sprite = m_sprites.at(START);
          break;
        case 'A':
          sprite = m_sprites.at(END);
          break;
        case '.':
          sprite = m_sprites.at(PATH);
          break;
        default:
          sprite = m_sprites.at(FIELD);
          break;
        }
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
        window.draw(sprite);
      }
    }
  }

  sf::Sprite Map::GetSprite(int pos){
    return m_sprites.at(pos);
  }
}

//*
namespace fs = boost::filesystem;
namespace td = towerdefense;

int main(int argc, char *argv[]) {

    // initialize
  td::World world;
  sf::RenderWindow window(sf::VideoMode(500, 500), "Tower Defense (version " GAME_VERSION ")");
  window.setKeyRepeatEnabled(false);
  td::Map mapLevel;

  // load resources
  fs::path bindir_path(argv[0]);
  bindir_path = bindir_path.parent_path();
  fs::path datadir_path = bindir_path / fs::path("\\res\\maps");

  std::cout << "Path: " << datadir_path << std::endl;

  td::ResourceManager manager;

  manager.addSearchDir(datadir_path.string());
  manager.addSearchDir(GAME_DATADIR);

  // add entities

  // main loop
  sf::Clock clock;
  while (window.isOpen()) {
    // input
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {

        switch (event.key.code) {
          case sf::Keyboard::Escape:
            window.close();
            break;

          default:
            break;
        }

      }
    }

    // update
    sf::Time elapsed = clock.restart();
    world.update(elapsed.asSeconds());
    mapLevel.render(window);

    window.display();
  }

  return 0;
}
//*/
