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
#include <towerdefense/TowerManager.h>
#include <towerdefense/EnemyManager.h>
#include <towerdefense/Levels.h>

namespace td = towerdefense;
namespace fs = boost::filesystem;
const int windowWidth=500;
const int windowHeight=500;

int main(int argc, char *argv[]) {

  // initialize
  td::World world;
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tower Defense (version " GAME_VERSION ")");
  window.setKeyRepeatEnabled(false);
  td::ImageHandler::initialize();
  td::Map mapLevel("res/maps/level2.txt", windowWidth, windowHeight);
// TODO (Erizino#1#): Fix enemy end
  td::TowerManager tMan;
  td::EnemyManager eMan(5, &mapLevel);
  td::Levels level(5, &tMan, &eMan, &mapLevel);

  // load resources
  fs::path bindir_path(argv[0]);
  bindir_path = bindir_path.parent_path();
  fs::path datadir_path = bindir_path / fs::path("\\res\\maps");

  std::cout << "Path: " << datadir_path << std::endl;

  td::ResourceManager manager;

  manager.addSearchDir(datadir_path.string());
  manager.addSearchDir(GAME_DATADIR);

  // add entities
  world.addEntity(&mapLevel);
  world.addEntity(&tMan);
  world.addEntity(&eMan);
  world.addEntity(&level);

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

          case sf::Keyboard::Space:
            mapLevel.changeLevel("res/maps/level2.txt");
            level.changeLevel(10);
            eMan.nextLevel(1, &mapLevel);
            break;

          default:
            break;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        tMan.addTower(localPosition.x, localPosition.y,mapLevel.getLevel());
      }
    }

    // update
    sf::Time elapsed = clock.restart();
    world.update(elapsed.asSeconds());

    // render
    window.clear(sf::Color::White);
    world.render(window);
    window.display();
  }

  td::ImageHandler::freedisk();
  return 0;
}
