#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include <towerdefense/Entity.h>

namespace towerdefense{

    class Map : public Entity {
public:
        Map();
        ~Map();

        void update();
        void render(sf::RenderWindow& window);
        sf::Sprite GetSprite(int pos);

        static const int PATH = 0;
        static const int FIELD = 1;
        static const int START = 2;
        static const int END = 3;
private:
        unsigned int m_tileWidth;
        unsigned int m_tileHeight;
        unsigned int m_width;
        unsigned int m_height;
        std::vector<std::string> m_level;
        std::vector<sf::Sprite> m_sprites;
    };
}

#endif // MAP_H
