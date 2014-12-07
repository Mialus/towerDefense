#include <towerdefense/graphics/Map.h>
#include <boost/filesystem.hpp>
#include <towerdefense/Resource.h>
#include <towerdefense/World.h>
#include <SFML/Graphics.hpp>
#include <towerdefense/computer/Ennemy.h>
#include <towerdefense/user/tower.h>
#include "../src/bin/config.h.in"

namespace towerdefense {

  Map::Map(){
    std::ifstream levelTxt("res/maps/level2.txt");
    std::string line;

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

void Map::moveGo(sf::RenderWindow& window, Ennemy en){
    unsigned int x=en.getPosX();
    unsigned int y=en.getPosY();
      std::string& line= m_level[y+1];

 if(line[x]=='.'){
 en.SetPosY(y+1);
 }else {
    line= m_level[y];
    if(line[x+1]=='.'){
    en.SetPosX(x+1);
    }else{
        line= m_level[y];
        if(line[x-1]=='.'){
        en.SetPosX(x-1);
        }else{
            line= m_level[y-1];
            if(line[x]=='.'){
            en.SetPosY(y-1);
            }
            }
        }
       }

}

  void Map::render(sf::RenderWindow& window, Ennemy en, Tower to){
    sf::Sprite sprite;

    for(unsigned int i=0; i<m_level.size(); ++i){
      std::string& line = m_level[i];
      for(unsigned int j=0; j<line.size(); ++j){
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
        if(((j)==to.getPosX())&& ((i==to.getPosY()))){// we put the tower on map
                sprite=to.Show();
        sprite.setPosition(to.getPosX()*m_tileWidth, to.getPosY()*m_tileHeight);
        }else{
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
        }

        if(((j)==en.getPosX())&& ((i==en.getPosY()))){//we put the enemy on map
                sprite=en.Show();
        sprite.setPosition(en.getPosX()*m_tileWidth, en.getPosY()*m_tileHeight);
        }else{
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
        }

        window.draw(sprite);
      }
    }
  }

  sf::Texture Map::GetTextureEnemy(){ return m_textureEnemy; }
  sf::Sprite Map::GetSpriteEnemy(){ return m_spriteEnemy; }
  sf::Texture Map::GetTextureTower(){ return m_textureTower; }
  sf::Sprite Map::GetSpriteTower(){ return m_spriteTower; }

}

namespace fs = boost::filesystem;
namespace td = towerdefense;
//*
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
Ennemy cube = Ennemy(1,10,1,25,"res/computer/ennemy2.jpg",1,1,0);
Tower to = Tower(1,1,4,2,"res/user/tower2.jpg");

  // main loop
  sf::Clock clock;
  while (window.isOpen()) {
    //Enemy

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
    mapLevel.render(window,cube,to);
    mapLevel.moveGo(window, cube);//we move the enemy
    window.display();
  }

  return 0;
}
//*/
