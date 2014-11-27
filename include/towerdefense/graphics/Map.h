#ifndef MAP_H
#define MAP_H



#endif // MAP_H

#include <vector>
#include <tmx/Map.h>
#include <boost/filesystem.hpp>

#include <gzzzt/client/Resource.h>
#include <gzzzt/client/ClientEntity.h>
#include <gzzzt/shared/Block.h>

namespace gzzzt {

    class ClientMap : public ClientEntity {
    public:

        ClientMap(const boost::filesystem::path & path, ResourceManager & resourceManager);
        virtual ~ClientMap();

        virtual void update(float dt) override;
        virtual void render(sf::RenderWindow& window) override;
    private:
        void drawGID(unsigned int x, unsigned int y, unsigned int GID, sf::RenderWindow& window);

    public:


    private:
        tmx::Map* m_tmxMap;
        std::vector<unsigned int> m_GID;
        sf::Texture* m_tileSetTexture;
        unsigned int m_tileWidth;
        unsigned int m_tileHeight;
        unsigned int m_width;
        unsigned int m_height;
    };

}


#endif // GZZZT_CLIENT_MAP_H
