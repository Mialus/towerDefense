#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include <towerdefense/Entity.h>
#include <towerdefense/computer/Ennemy.h>
#include <towerdefense/user/tower.h>

namespace towerdefense{

    class Map : public Entity {
public:
        Map();
        ~Map();

        void update();
        void render(sf::RenderWindow& window, Ennemy en, Tower to);
        sf::Texture GetTextureEnemy();
        sf::Sprite GetSpriteEnemy();
        sf::Texture GetTextureTower();
        sf::Sprite GetSpriteTower();
private:
        unsigned int m_tileWidth;
        unsigned int m_tileHeight;
        unsigned int m_width;
        unsigned int m_height;
        std::vector<std::string> m_level;
        sf::Texture m_textureEnemy;
        sf::Sprite m_spriteEnemy;
        sf::Texture m_textureTower;
        sf::Sprite m_spriteTower;
    };
}

#endif // MAP_H
