/*
 * Copyright (c) 2014, Julien Bernard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <boost/filesystem.hpp>
#include <SFML/Graphics.hpp>

#include "../src/bin/config.h.in"

#include <towerdefense/Map.h>
#include <towerdefense/Resource.h>
#include <towerdefense/World.h>
#include <towerdefense/Enemy.h>

namespace td = towerdefense;
namespace fs = boost::filesystem;
//*
int main(int argc, char *argv[]) {

  // initialize
  td::World world;
  sf::RenderWindow window(sf::VideoMode(500, 500), "Tower Defense (version " GAME_VERSION ")");
  window.setKeyRepeatEnabled(false);
  td::ImageHandler::initialize(500, 500);
  td::Map mapLevel("res/maps/level1.txt");

  // load resources
  fs::path bindir_path(argv[0]);
  bindir_path = bindir_path.parent_path();
  fs::path datadir_path = bindir_path / fs::path("\\res\\maps");

  std::cout << "Path: " << datadir_path << std::endl;

  td::ResourceManager manager;

  manager.addSearchDir(datadir_path.string());
  manager.addSearchDir(GAME_DATADIR);

  // add entities
  //(int speed,int life,int level,int coin,const char* image, int defense, int posX, int posY)
//  td::Enemy cube = td::Enemy(1,10,1,25,"res/computer/ennemy2.jpg",1,1,0);
//  td::Tower to = td::Tower(1,1,4,2,"res/user/tower2.jpg");
//  cube.SetPosXb(cube.GetPosX());
//  cube.SetPosYb(cube.GetPosY());

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

    // render
    window.clear(sf::Color::White);
    world.render(window);
    mapLevel.render(window);
    window.display();
  }

  return 0;
}
//*/
